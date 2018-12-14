#ifndef _MTDCSSTRUCT_H_
#define _MTDCSSTRUCT_H_

#include "mtconst.h"

enum EmDcsAdpOper
{
	emWbLineOperInfo = 0, 	// TDCSAdpWbLineOperInfo
	emWbCircleOperInfo, 	// TDCSAdpWbCircleOperInfo
	emWbRectangleOperInfo,
	emWbPencilOperInfo, 	// TDCSAdpWbPencilOperInfo
	emWbColorPenOperInfo, 	// TDCSAdpWbColorPenOperInfo
	emWbImageOperInfo, 	// TDCSAdpWbImageOperInfo
	emWbAddSubPageInfo, 	// TDCSAdpWbAddSubPageInfo
	emWbEraseOperInfo, 	// TDCSAdpWbEraseOperInfo
	emWbZoomInfo, 			// TDCSAdpWbZoomInfo
	emWbUndo,
	emWbRedo,
	emWbRotateLeft,
	emWbRotateRight,
	emWbClearScreen,
	emWbScrollScreen,
	
	emWbFullScreen,
	emWb100ProportionScreen,
	emWbReginErase, 
	emWbInsertPic,
	emWbPitchPicZoom,
	emWbPitchPicRotate,
	emWbPitchPicDrag,
	emWbPitchPicDel, 
};

enum EmDcsAdpConnectType
{
	emConnectLogin = 0,			       	// 用于登录注册
	emConnectConf = 1,				    // 用于会议相关
};

enum EmDcsAdpType
{
//	emTypeTrueLink = 0,			       	// 软终端
//	emTypeTruesens = 1,				       	// 硬终端
//	emTypeMobile = 2,                    	//移动终端
	emTypeUnknown = 0,					// 未知
	emTypeTrueLink = 1,			       	// 致玲
	emTypeTrueTouchPhoneIOS = 2,		// 手机-IOS
	emTypeTrueTouchPadIOS = 3,			// 平板-IOS
	emTypeTrueTouchPhoneAndroid = 4,	// 手机-android
	emTypeTrueTouchPadAndroid = 5,		// 平板-android
	emTypeTrueSens = 6,					// 硬终端
	emTypeIMIX = 7,						// imix
	emTypeThirdPartyTer = 8,			// 第三方终端
	emTypeButt = 255,
};

enum EmDcsAdpRole
{
	emRoleManage = 0,			       	// 管理方
	emRoleOper = 1,				       	// 协作方
	emRoleUser = 2,                      	// 与会方
	emRoleErr = 10,						//未填
};

enum EmDcsAdpConfMode
{
	emConfModeManage = 0,			       	// 主席控制
	emConfModeAuto = 1,				       	// 自动协作
};

enum EmDcsAdpConfType
{
	emConfTypeP2P = 0,			       	// 点对点
	emConfTypeMCC = 1,			       	// 多点
};

enum EmDcsAdpWbMode
{
	emWbModeWB = 0,			       	// 白板
	emWBModeDOC = 1,		       	// 文档
};

enum EmDcsAdpWbEntityType
{
	emUnknow = 0,
	emLine = 1,			// 直线
	emCircle = 2,		// 圆形
	emPencil = 3,		// 铅笔
	emColorPen = 4,		// 水彩笔
	emImage = 5,		// 图片
};

// 图片文件所处状态
enum EmDcsAdpWbImageState
{
	emImageStateDownloading = 0,        // 文件正在接收，请耐心等待... 
	emImageStateDownLoadFail = 1,		// 文件接收失败，非常抱歉！！！
	emImageStateOwnerAlreadyLeave = 2,	// 文件同步失败，发起方可能已断开连接
	emImageStateDownLoadOk = 3,			// 文件接收成功，即将显示
	emImageStateInit = 4,		        // 初始状态
	emImageStateConvertFail = 5,		// 文件转换失败，可能文件错误或已损坏
	emImageStateSelfAlreadyLeave = 6,    // 文件接收未完成，已离开会议
};

// 白板模式
enum EmDcsAdpWBMode
{ 
	emWbModeUnkown = 0,   // 未知
	emWbModeWhiteBoard = 1,   // 空白白板模式（非文档模式）
	emWbModeDOC = 2,          // 文档模式
};

enum EmDcsAdpConnectErrCode
{
	emConfSuccess = 1,  // 会议服务器建链成功
	emConfFailed = 2,	// 会议服务器建链失败
	emConfDisconnect = 3,	// 会议服务器中途断链
	emLoginSuccess = 4,		// 注册服务器建链成功
	emLoginFailed = 5,		// 注册服务器建链失败
	emLoginDisconnect = 6,	// 注册服务器建链中途断链
};

enum EmDcsAdpRejectJoinConfCode
{
	emRejectJoinConf_start          = 0,
	emRejectJoinConf_busy           = 1,
	emRejectJoinConf_normal         = 2,
	emRejectJoinConf_rejected       = 3,
	emRejectJoinConf_unreachable    = 4,
	emRejectJoinConf_unknown        = 5,
	emRejectJoinConf_end            = 255,
};


typedef struct tagTDCSAdpResult
{
	BOOL32     	m_bSucces;
	u32			m_dwErrorCode;

	s8			m_achConfE164[MT_STR_LEN_64+1];

	tagTDCSAdpResult() { memset(this, 0, sizeof(tagTDCSAdpResult)); }

}*PTDCSAdpResult, TDCSAdpResult;

typedef struct tagTDCSAdpBoardResult
{
	BOOL32     	m_bSucces;
	u32			m_dwErrorCode;

	s8			m_achConfE164[MT_STR_LEN_64+1];
	s8			m_achTabId[MT_STR_LEN_64+1];
	u32			m_dwPageId;

	tagTDCSAdpBoardResult() { memset(this, 0, sizeof(tagTDCSAdpBoardResult)); }

}*PTDCSAdpBoardResult, TDCSAdpBoardResult;


typedef struct tagTDCSAdpSetConfInfoResult
{
	BOOL32     	m_bSucces;
	u32			m_dwErrorCode;

	s8			m_achConfE164[MT_STR_LEN_64+1];
	s8			m_achConfName[MT_STR_LEN_256+1];
	EmDcsAdpConfMode	m_emConfMode;
	EmDcsAdpConfType	m_emConfType;

	tagTDCSAdpSetConfInfoResult() { memset(this, 0, sizeof(tagTDCSAdpSetConfInfoResult)); }

}*PTDCSAdpSetConfInfoResult, TDCSAdpSetConfInfoResult;

//登录APS服务器所需的用户名密码
typedef struct tagTDCSAdpApsLoginParam
{
	s8	m_achUsername[MT_STR_LEN_128+1]; ///< 用户名
	s8	m_achPassword[MT_STR_LEN_64+1]; ///< 明文密码

	tagTDCSAdpApsLoginParam() { memset(this, 0, sizeof(tagTDCSAdpApsLoginParam)); }

}*PTDCSAdpApsLoginParam, TDCSAdpApsLoginParam;

typedef struct tagTDCSAdpOperReq
{
	s8				m_achConfE164[MT_STR_LEN_64+1];
	s8				m_achTabId[MT_STR_LEN_64+1];
	u32				m_dwWbPageid;

	tagTDCSAdpOperReq() { memset(this, 0, sizeof(tagTDCSAdpOperReq)); }

}*PTDCSAdpOperReq, TDCSAdpOperReq;


typedef struct tagTDCSAdpConfUserInfo
{
	s8				m_achE164[MT_E164_LEN+1];
	s8				m_achName[MT_STR_LEN_256+1];     			// 只有在添加与会方，删除与会方用到
	EmDcsAdpType	m_emMttype;
	//EmDcsAdpRole	m_emRole;         		// 只有在会议里才生效
	BOOL32			m_bOnline; 			// 暂时只在获取与会人员列表中有效
	BOOL32			m_bIsOper;
	BOOL32			m_bIsConfAdmin;

	tagTDCSAdpConfUserInfo() { memset(this, 0, sizeof(tagTDCSAdpConfUserInfo)); }

}*PTDCSAdpConfUserInfo, TDCSAdpConfUserInfo;

typedef struct tagTDCSAdpCreateConf
{
	EmDcsAdpConfType		m_emConfType;
	s8						m_achConfE164[MT_STR_LEN_64+1];
	s8						m_achConfName[MT_STR_LEN_128+1];
	EmDcsAdpConfMode		m_emConfMode;

	u32						m_dwListNum;
	TDCSAdpConfUserInfo		m_atUserList[MT_DCS_CONF_USER_MAX+1];

	s8						m_achConfAdminE164[MT_E164_LEN+1];
	EmDcsAdpType			m_emMtType;

	tagTDCSAdpCreateConf() { memset(this, 0, sizeof(tagTDCSAdpCreateConf)); }

}*PTDCSAdpCreateConf, TDCSAdpCreateConf;

typedef struct tagTDCSAdpConfAddr
{
	s8			m_achIp[MT_STR_LEN_64+1];
	s8			m_achDomain[MT_STR_LEN_256+1];
	u32			m_dwPort;

	tagTDCSAdpConfAddr() { memset(this, 0, sizeof(tagTDCSAdpConfAddr)); }

}*PTDCSAdpConfAddr, TDCSAdpConfAddr;

typedef struct tagTDCSAdpCreateConfResult
{
	s8			m_achConfE164[MT_STR_LEN_64+1];
	s8			m_achConfName[MT_STR_LEN_128+1];
	BOOL32		m_bSuccess;
	u32			m_dwErrorCode;
	EmDcsAdpConfMode	m_emConfMode;
	EmDcsAdpConfType	m_emConfType; 

	TDCSAdpConfAddr    m_tConfAddr;

	tagTDCSAdpCreateConfResult() { memset(this, 0, sizeof(tagTDCSAdpCreateConfResult)); }
	
}*PTDCSAdpCreateConfResult, TDCSAdpCreateConfResult;

typedef struct tagTDCSAdpInviteUsr
{
	s8				m_achConfE164[MT_STR_LEN_64+1];
/*	s8				m_achConfName[MT_STR_LEN_128+1];*/
	TDCSAdpConfAddr    	m_tConfAddr;

	tagTDCSAdpInviteUsr() { memset(this, 0, sizeof(tagTDCSAdpInviteUsr)); }

}*PTDCSAdpInviteUsr, TDCSAdpInviteUsr;

typedef struct tagTDCSAdpJoinConfResult
{
	s8			m_achConfE164[MT_STR_LEN_64+1];
	s8			m_achConfName[MT_STR_LEN_128+1];
	BOOL32		m_bSuccess;
	u32 		m_dwErrorCode;
	EmDcsAdpConfMode	m_emConfMode;
	EmDcsAdpConfType	m_emConfType;
	//EmDcsAdpRole		m_emRole;
	BOOL32		m_bIsOper;					// 是否为协作方
	BOOL32		m_bIsConfAdmin;				// 是否为管理方

	tagTDCSAdpJoinConfResult() { memset(this, 0, sizeof(tagTDCSAdpJoinConfResult)); }

}*PTDCSAdpJoinConfResult, TDCSAdpJoinConfResult;

typedef struct tagTDCSAdpMemberInfo
{
	s8					m_achConfE164[MT_STR_LEN_64+1];

	u32			m_dwListNum;
	TDCSAdpConfUserInfo		m_atUserList[MT_DCS_CONF_USER_MAX+1];

	tagTDCSAdpMemberInfo() { memset(this, 0, sizeof(tagTDCSAdpMemberInfo)); }

}*PTDCSAdpMemberInfo, TDCSAdpMemberInfo;

typedef struct tagTDCSAdpConfInfo
{
	s8		m_achConfE164[MT_STR_LEN_64+1];
	s8		m_achConfName[MT_STR_LEN_128+1];
	EmDcsAdpConfMode			m_emConfMode;
	EmDcsAdpConfType			m_emConfType;

	tagTDCSAdpConfInfo() { memset(this, 0, sizeof(tagTDCSAdpConfInfo)); }

}*PTDCSAdpConfInfo, TDCSAdpConfInfo;

/*
typedef struct tagTDCSAdpSetUserRole
{
	s8				m_achConfE164[MT_STR_LEN_64+1];

	u32				m_dwListNum;
	TDCSAdpConfUserInfo		m_atUserList[MT_DCS_CONF_USER_MAX+1];   // 这里需要填写用户角色

	tagTDCSAdpSetUserRole() { memset(this, 0, sizeof(tagTDCSAdpSetUserRole)); }

}*PTDCSAdpSetUserRole, TDCSAdpSetUserRole;
*/

typedef struct tagTDCSAdpGetUserList
{
	u32					m_dwListNum;
	TDCSAdpConfUserInfo	m_atUserList[MT_DCS_CONF_USER_MAX+1];   // 这里有用户角色以及在线状态

	tagTDCSAdpGetUserList() { memset(this, 0, sizeof(tagTDCSAdpGetUserList)); }

}*PTDCSAdpGetUserList, TDCSAdpGetUserList;

typedef struct tagTDCSAdpBoardInfo
{
	s8					m_achWbName[MT_STR_LEN_256+1];
	EmDcsAdpWbMode		m_emWbMode;
	u32 				m_dwWbPageNum;
	u32					m_dwWbCreateTime;		// 平台成功响应后，平台填写
	s8 					m_achTabId[MT_STR_LEN_64+1];			// s8，由终端自己生成
//	s8					m_achImagePath[MT_STR_LEN_512+1];			// 平台成功响应后，平台填写
//	s8					m_achElementPath[MT_STR_LEN_512+1];		// 平台成功响应后，平台填写
	u32 				m_dwPageId;				

	s8					m_achWbCreatorE164[MT_E164_LEN+1];
	u32					m_dwWbWidth;
	u32					m_dwWbHeight;
	u32					m_dwWbSerialNumber;  // 白板序列号，递增，标记白板创建序号
//	u32					m_dwInconvert;

	s8					m_achUploadUrl[MT_STR_LEN_512+1];
	s8					m_achElementUrl[MT_STR_LEN_512+1];
	s8					m_achDownloadUrl[MT_STR_LEN_512+1];


	u32					m_dwWbAnonyId;			// 平台成功响应后，平台填写（仅限于白板模式）

	tagTDCSAdpBoardInfo() { memset(this, 0, sizeof(tagTDCSAdpBoardInfo)); }

}*PTDCSAdpBoardInfo, TDCSAdpBoardInfo;

//新添加的删除电子白板时通知与会方时使用
typedef struct tagTDCSAdpDelWhiteBoard
{
    s8					m_achConfE164[MT_STR_LEN_64+1];
    s8                  m_achIndex[MT_STR_LEN_64+1];
    s8                  m_achFromE164[MT_STR_LEN_64+1];	
    tagTDCSAdpDelWhiteBoard() { memset(this, 0, sizeof(tagTDCSAdpDelWhiteBoard)); }

}*PTDCSAdpDelWhiteBoard, TDCSAdpDelWhiteBoard;

typedef struct tagTDCSAdpNewWhiteBoard
{
	s8					m_achConfE164[MT_STR_LEN_64+1];
	TDCSAdpBoardInfo	m_tBoardinfo;
	
	tagTDCSAdpNewWhiteBoard() { memset(this, 0, sizeof(tagTDCSAdpNewWhiteBoard)); }
	
}*PTDCSAdpNewWhiteBoard, TDCSAdpNewWhiteBoard;

typedef struct tagTDCSAdpGetAllBoard
{
	s8					m_achConfE164[MT_STR_LEN_64+1];

	u32					m_dwBoardNum;
	TDCSAdpBoardInfo	m_atBoardInfo[MT_DCS_WB_MAX+1];
	
	tagTDCSAdpGetAllBoard() { memset(this, 0, sizeof(tagTDCSAdpGetAllBoard)); }

}*PTDCSAdpGetAllBoard, TDCSAdpGetAllBoard;

typedef struct tagTDCSAdpSwitchReq
{
	s8			m_achConfE164[MT_STR_LEN_64+1];
	s8 			m_achTabId[MT_STR_LEN_64+1];
	u32 		m_dwWbPageId;

	tagTDCSAdpSwitchReq() { memset(this, 0, sizeof(tagTDCSAdpSwitchReq)); }

}*PTDCSAdpSwitchReq, TDCSAdpSwitchReq;

typedef struct tagTDCSAdpUserInfo
{
	s8			m_achConfE164[MT_STR_LEN_64+1];
	s8			m_achConfName[MT_STR_LEN_128+1];
	TDCSAdpConfUserInfo		m_tUserInfo;

	tagTDCSAdpUserInfo() { memset(this, 0, sizeof(tagTDCSAdpUserInfo)); }

}*PTDCSAdpUserInfo, TDCSAdpUserInfo;


typedef struct tagTDCSAdpUserInfos
{
	s8 				m_achConfE164[MT_STR_LEN_64+1];
	s8 				m_achConfName[MT_STR_LEN_128+1];

	u32						m_dwListNum;
	TDCSAdpConfUserInfo		m_atUserInfoList[MT_DCS_CONF_USER_MAX+1];

	tagTDCSAdpUserInfos() { memset(this, 0, sizeof(tagTDCSAdpUserInfos)); }

}*PTDCSAdpUserInfos, TDCSAdpUserInfos;


typedef struct tagTDCSAdpUserRole
{
	s8 						m_achConfE164[MT_STR_LEN_64+1];

	u32						m_dwListNum;
	TDCSAdpConfUserInfo		m_atUserInfoList[MT_DCS_CONF_USER_MAX+1];

	tagTDCSAdpUserRole() { memset(this, 0, sizeof(tagTDCSAdpUserRole)); }

}*PTDCSAdpUserRole, TDCSAdpUserRole;

typedef struct tagTDCSAdpWbPoint
{
	s32		m_nPosx;
	s32		m_nPosy;

	tagTDCSAdpWbPoint() { memset(this, 0, sizeof(tagTDCSAdpWbPoint)); }

}*PTDCSAdpWbPoint, TDCSAdpWbPoint;

typedef struct tagTDCSAdpWbEntity
{
	s8		m_achEntityId[MT_STR_LEN_64+1];    // 现在使用GUID来填写
	BOOL32	m_bLock;

	tagTDCSAdpWbEntity() { memset(this, 0, sizeof(tagTDCSAdpWbEntity)); }

}*PTDCSAdpWbEntity, TDCSAdpWbEntity;


typedef struct tagTDCSAdpWbLine
{
	TDCSAdpWbEntity		m_tEntity;     // 基本信息
	TDCSAdpWbPoint 		m_tBeginPt;    // 起点坐标
	TDCSAdpWbPoint 		m_tEndPt;      // 终端坐标
	u32					m_dwLineWidth;	// 线宽
	u32 				m_dwRgb;        // 颜色

	tagTDCSAdpWbLine() { memset(this, 0, sizeof(tagTDCSAdpWbLine)); }

}*PTDCSAdpWbLine, TDCSAdpWbLine;

typedef struct tagTDCSAdpWbCircle
{
	TDCSAdpWbEntity 	m_tEntity;         // 基本信息
	TDCSAdpWbPoint 	m_tBeginPt;        // 起点坐标
	TDCSAdpWbPoint 	m_tEndPt;          // 终端坐标
	u32				m_dwLineWidth;		 // 线宽
	u32 			m_dwRgb;           // 颜色

	tagTDCSAdpWbCircle() { memset(this, 0, sizeof(tagTDCSAdpWbCircle)); }

}*PTDCSAdpWbCircle, TDCSAdpWbCircle;

typedef struct tagTDCSAdpWbRectangle
{
	TDCSAdpWbEntity 	m_tEntity;         // 基本信息
	TDCSAdpWbPoint 	m_tBeginPt;        // 起点坐标
	TDCSAdpWbPoint 	m_tEndPt;          // 终端坐标
	u32				m_dwLineWidth;		 // 线宽
	u32 			m_dwRgb;           // 颜色

	tagTDCSAdpWbRectangle() { memset(this, 0, sizeof(tagTDCSAdpWbRectangle)); }

}*PTDCSAdpWbRectangle, TDCSAdpWbRectangle;

// 铅笔图元类（画曲线）
typedef struct tagTDCSAdpWbPencil
{
	TDCSAdpWbEntity 	m_tEntity;      // 基本信息

	u32					m_dwPointNum;
	TDCSAdpWbPoint 		m_atPList[MT_DCS_POINT_MAX+1]; 		 // 曲线点信息列表

	u32					m_dwLineWidth;	 // 线宽
	u32 				m_dwRgb;          // 颜色 

	tagTDCSAdpWbPencil() { memset(this, 0, sizeof(tagTDCSAdpWbPencil)); }

}*PTDCSAdpWbPencil, TDCSAdpWbPencil;

// 彩笔图元类（画彩色曲线）
typedef struct tagTDCSAdpWbColorPen
{
	TDCSAdpWbEntity 	m_tEntity;                // 基本信息
	
	u32					m_dwColorPenNum;
	TDCSAdpWbPoint		m_atCPList[MT_DCS_POINT_MAX+1];                  // 曲线点信息列表 
	u32					m_dwLineWidth;	           // 线宽
	u32 				m_dwRgb;     

	tagTDCSAdpWbColorPen() { memset(this, 0, sizeof(tagTDCSAdpWbColorPen)); }

}*PTDCSAdpWbColorPen, TDCSAdpWbColorPen;

// 图片图元类
typedef struct tagTDCSAdpWbImage
{
	TDCSAdpWbEntity 		m_tEntity;				// 基本信息
	TDCSAdpWbPoint 			m_tBoardPt;				// 边界矩形左上角坐标
	u32 					m_dwWidth;              // 边界矩形宽度
	u32 					m_dwHeight;             // 边界矩形宽度
	EmDcsAdpWbImageState	m_emNetworkstate;       // 网络状态信息
	s8 						m_achFileName[MT_STR_LEN_256+1];           // 文件名（utf8编码）
	BOOL32					m_bBkImg;				// 是否是文档底图

	tagTDCSAdpWbImage() { memset(this, 0, sizeof(tagTDCSAdpWbImage)); }

}*PTDCSAdpWbImage, TDCSAdpWbImage;

// 线绘图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
typedef struct tagTDCSAdpWbLineOperInfo
{
	s8  				m_achTabId[MT_STR_LEN_64+1];            // 白板tab id（guid）
	u32 				m_dwSubPageId;        // 子页面id
	TDCSAdpWbLine 		m_tLine;             // 线操作信息

	tagTDCSAdpWbLineOperInfo() { memset(this, 0, sizeof(tagTDCSAdpWbLineOperInfo)); }

}*PTDCSAdpWbLineOperInfo, TDCSAdpWbLineOperInfo;

// 圆绘图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
typedef struct tagTDCSAdpWbCircleOperInfo
{
	s8  				m_achTabId[MT_STR_LEN_64+1];            // 白板tab id（guid）
	u32 				m_dwSubPageId;        // 子页面id
	TDCSAdpWbCircle 	m_tCircle;           // 圆操作信息

	tagTDCSAdpWbCircleOperInfo() { memset(this, 0, sizeof(tagTDCSAdpWbCircleOperInfo)); }

}*PTDCSAdpWbCircleOperInfo, TDCSAdpWbCircleOperInfo;

// 矩形绘图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
typedef struct tagTDCSAdpWbRectangleOperInfo
{
	s8  				m_achTabId[MT_STR_LEN_64+1];            // 白板tab id（guid）
	u32 				m_dwSubPageId;        // 子页面id
	TDCSAdpWbRectangle 	m_tRectangle;           // 矩形操作信息

	tagTDCSAdpWbRectangleOperInfo() { memset(this, 0, sizeof(tagTDCSAdpWbRectangleOperInfo)); }

}*PTDCSAdpWbRectangleOperInfo, TDCSAdpWbRectangleOperInfo;

// 铅笔绘图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
typedef struct tagTDCSAdpWbPencilOperInfo
{
	s8  				m_achTabId[MT_STR_LEN_64+1];            // 白板tab id（guid）
	u32 				m_dwSubPageId;        // 子页面id
	TDCSAdpWbPencil 	m_tPencil;           // 铅笔操作信息

	tagTDCSAdpWbPencilOperInfo() { memset(this, 0, sizeof(tagTDCSAdpWbPencilOperInfo)); }

}*PTDCSAdpWbPencilOperInfo, TDCSAdpWbPencilOperInfo;

// 彩笔绘图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
typedef struct tagTDCSAdpWbColorPenOperInfo
{
	s8  				m_achTabId[MT_STR_LEN_64+1];            // 白板tab id（guid）
	u32 				m_dwSubPageId;        // 子页面id
	TDCSAdpWbColorPen		m_tColoePen;         // 彩笔操作信息

	tagTDCSAdpWbColorPenOperInfo() { memset(this, 0, sizeof(tagTDCSAdpWbColorPenOperInfo)); }

}*PTDCSAdpWbColorPenOperInfo, TDCSAdpWbColorPenOperInfo;

typedef struct tagTDCSAdpWbImageOperInfo
{
	s8					m_achTabId[MT_STR_LEN_64+1];                // 白板tab id（guid）
	u32					m_dwSubPageId;            // 子页面id
	TDCSAdpWbImage		m_tImage;            	// 图片图元操作信息

	tagTDCSAdpWbImageOperInfo() { memset(this, 0, sizeof(tagTDCSAdpWbImageOperInfo)); }

}*PTDCSAdpWbImageOperInfo, TDCSAdpWbImageOperInfo;

// 标记当前操作文档的tab页和subpage
typedef struct tagTDCSAdpWbTabPageIdInfo
{
	s8 		m_achTabId[MT_STR_LEN_64+1];    		// 白板tab id（guid）
	u32 	m_dwSubPageId;   	// 子页id

	tagTDCSAdpWbTabPageIdInfo() { memset(this, 0, sizeof(tagTDCSAdpWbTabPageIdInfo)); }

}*PTDCSAdpWbTabPageIdInfo, TDCSAdpWbTabPageIdInfo;

// 删除tab页携带的信息
// typedef struct tagTDCSAdpWbRemovePageIdInfo
// {
// 	s8 		m_achTabId[MT_STR_LEN_64+1];   			// 白板tab id（guid）
// 	s8 		m_achNextTabPageId[MT_STR_LEN_256+1];   	// 下一个tab白板页id
// 
// 	tagTDCSAdpWbRemovePageIdInfo() { memset(this, 0, sizeof(tagTDCSAdpWbRemovePageIdInfo)); }
// 
// }*PTDCSAdpWbRemovePageIdInfo, TDCSAdpWbRemovePageIdInfo;


// 白板中添加子页信息，打开文档时，根据文档的总页数在当前白板中添加多个子页
typedef struct tagTDCSAdpWbAddSubPageInfo
{
	s8 		m_achTabId[MT_STR_LEN_64+1];             // 白板tab id（guid）
	u32 	m_dwSubPageCount;       // 子页总数，即打开的文档的总页数

	tagTDCSAdpWbAddSubPageInfo() { memset(this, 0, sizeof(tagTDCSAdpWbAddSubPageInfo)); }

}*PTDCSAdpWbAddSubPageInfo, TDCSAdpWbAddSubPageInfo;


// 切换白板页信息，切换白板页包括两种情况：
// 1)在当前白板中从一个子页切换到另一子页，即前后翻页，或者翻到指定的页面；
// 2)切换到另一个白板中
// typedef struct tagTDCSAdpWbSwitchPageInfo
// {
// 	s8 		m_achTabId[MT_STR_LEN_64+1];             // 白板tab id（guid）
// 	u32 	m_dwSubPageId;              // 子页id
// 
// 	tagTDCSAdpWbSwitchPageInfo() { memset(this, 0, sizeof(tagTDCSAdpWbSwitchPageInfo)); }
// 
// }*PTDCSAdpWbSwitchPageInfo, TDCSAdpWbSwitchPageInfo;

// 客户端给服务器发送请求目标页图片请求
// typedef struct tagTDCSAdpWbReqPageImage
// {
// 	s8 		m_achImgId[MT_STR_LEN_256+1];         // 请求的图片图元id（guid）
// 	s8 		m_achTabId[MT_STR_LEN_64+1];         // 白板tab id（guid）
// 	u32 	m_dwSubPageId;        // 当前子页id
// 	u32 	m_dwOwnerIndex;       // 该白板页文档属主在服务器上的userindex，服务器收到请求后，需要给该index对应的属主发请求
// 
// 	tagTDCSAdpWbReqPageImage() { memset(this, 0, sizeof(tagTDCSAdpWbReqPageImage)); }
// 
// }*PTDCSAdpWbReqPageImage, TDCSAdpWbReqPageImage;

// 矩形擦除
typedef struct tagTDCSAdpWbEraseOperInfo
{
	s8 					m_achTabId[MT_STR_LEN_64+1];            // 白板tab id（guid）
	u32 				m_dwSubPageId;   	// 子页id
	TDCSAdpWbPoint		m_tBeginPt;          // 矩形擦除区域的开始坐标（此参数矩形擦除使用）
	TDCSAdpWbPoint		m_tEndPt;            // 矩形擦除区域的结束坐标（此参数矩形擦除使用）
	BOOL32				m_bNexVision;		// 是否网呈终端

	tagTDCSAdpWbEraseOperInfo() { memset(this, 0, sizeof(tagTDCSAdpWbEraseOperInfo)); }

}*PTDCSAdpWbEraseOperInfo, TDCSAdpWbEraseOperInfo;

// 放大/缩小、横向/纵向自适应
typedef struct tagTDCSAdpWbZoomInfo
{
	s8 		m_achTabId[MT_STR_LEN_64+1];       // 白板tab id（guid）
	u32 	m_dwZoom;           // 当前页缩放倍数，取百分制，例如100.0，对应100%

	tagTDCSAdpWbZoomInfo() { memset(this, 0, sizeof(tagTDCSAdpWbZoomInfo)); }

}*PTDCSAdpWbZoomInfo, TDCSAdpWbZoomInfo;

// 发送图片文件的信息
typedef struct tagTDCSAdpWbSendImgFileInfo
{
	u32		m_dwFileSize;          // 文件大小
	s8 		m_achFileId[MT_STR_LEN_128+1];       // 图片文件id（即图片图元id）
	s8 		m_achFileName[MT_STR_LEN_512+1];    // 文件完整路径（utf8编码）

	tagTDCSAdpWbSendImgFileInfo() { memset(this, 0, sizeof(tagTDCSAdpWbSendImgFileInfo)); }

}*PTDCSAdpWbSendImgFileInfo, TDCSAdpWbSendImgFileInfo;

typedef struct tagTDCSAdpOperContent
{
	EmDcsAdpOper	m_emOper;
	u32 			m_dwMsgId;
	s8 				m_achTabId[MT_STR_LEN_64+1];
	u32 			m_dwWbPageId;

	u32				m_MsgSequence;  // 服务器生成

	s8				m_achConfE164[MT_STR_LEN_64+1];
	s8				m_achFromE164[MT_STR_LEN_64+1];

	tagTDCSAdpOperContent() { memset(this, 0, sizeof(tagTDCSAdpOperContent)); }

}*PTDCSAdpOperContent, TDCSAdpOperContent;


typedef struct tagTDCSAdpOperator
{
	s8			m_achConfE164[MT_STR_LEN_64+1];

	u32						m_dwOperListNum;
	TDCSAdpConfUserInfo		m_atOperList[MT_DCS_CONF_USER_MAX+1];

	tagTDCSAdpOperator() { memset(this, 0, sizeof(tagTDCSAdpOperator)); }

}*PTDCSAdpOperator, TDCSAdpOperator;


typedef struct tagTDCSAdpScrollScreenInfo
{
	s8 				m_achTabId[MT_STR_LEN_64+1];		//tab白板页
	u32				m_dwSubPageId;		//子页ID
	TDCSAdpWbPoint	m_tPoint;		//滚动到的目标点坐标

	tagTDCSAdpScrollScreenInfo() { memset(this, 0, sizeof(tagTDCSAdpScrollScreenInfo)); }

}*PTDCSAdpScrollScreenInfo, TDCSAdpScrollScreenInfo;

// 全屏显示/100比例显示
typedef struct tagTDCSAdpWbDisPlayInfo
{
	s8 				m_achTabId[MT_STR_LEN_64+1];		//tab白板页
	u32				m_dwSubPageId;		//子页ID
	s8				m_aachMatrixValue[ MT_DCS_MATRIXVALUE+1 ][MT_STR_LEN_32+1];

	tagTDCSAdpWbDisPlayInfo() { memset(this, 0, sizeof(tagTDCSAdpWbDisPlayInfo)); }

}*PTDCSAdpWbDisPlayInfo, TDCSAdpWbDisPlayInfo;


// 区域矩形擦除
typedef struct tagTDCSAdpWbReginEraseOperInfo
{
	s8 					m_achTabId[MT_STR_LEN_64+1];            // 白板tab id（guid）
	u32 				m_dwSubPageId;   	// 子页id
	s8					m_achGraphsId[MT_STR_LEN_128+1];		// 图元ID
	u32					m_dwEraseWidth;
	u32					m_dwEraseHeight;
	
	u32					m_dwPointCount;
	TDCSAdpWbPoint		m_atPoint[MT_DCS_POINT_MAX+1];

	tagTDCSAdpWbReginEraseOperInfo() { memset(this, 0, sizeof(tagTDCSAdpWbReginEraseOperInfo)); }

}*PTDCSAdpWbReginEraseOperInfo, TDCSAdpWbReginEraseOperInfo;

//插入图片
typedef struct tagTDCSAdpWbInsertPicOperInfo
{
	s8 					m_achTabId[MT_STR_LEN_64+1];            // 白板tab id（guid）
	u32 				m_dwSubPageId;   	// 子页id
	s8					m_achImgId[MT_STR_LEN_128+1];		// 图元ID
	u32					m_dwImgWidth;
	u32					m_dwImgHeight;
	TDCSAdpWbPoint		m_tPoint;
	s8					m_achPicName[MT_STR_LEN_128+1];

	s8					m_aachMatrixValue[ MT_DCS_MATRIXVALUE+1 ][MT_STR_LEN_32+1];

	tagTDCSAdpWbInsertPicOperInfo() { memset(this, 0, sizeof(tagTDCSAdpWbInsertPicOperInfo)); }

}*PTDCSAdpWbInsertPicOperInfo, TDCSAdpWbInsertPicOperInfo;


typedef struct tagTDCSAdpWbGraphsInfo
{
	s8					m_achGraphsId[MT_STR_LEN_128+1];		// 图元ID
	s8					m_aachMatrixValue[ MT_DCS_MATRIXVALUE+1 ][MT_STR_LEN_32+1];

	tagTDCSAdpWbGraphsInfo() { memset(this, 0, sizeof(tagTDCSAdpWbGraphsInfo)); }
}*PTDCSAdpWbGraphsInfo, TDCSAdpWbGraphsInfo;

// 选中图片（准备进行操作）
typedef struct tagTDCSAdpWbPitchPicOperInfo
{
	s8 					m_achTabId[MT_STR_LEN_64+1];            // 白板tab id（guid）
	u32 				m_dwSubPageId;   	// 子页id

	u32					m_dwGraphsCount;
	TDCSAdpWbGraphsInfo	m_atGraphsInfo[MT_DCS_POINT_MAX+1];

	tagTDCSAdpWbPitchPicOperInfo() { memset(this, 0, sizeof(tagTDCSAdpWbPitchPicOperInfo)); }

}*PTDCSAdpWbPitchPicOperInfo, TDCSAdpWbPitchPicOperInfo;


// 选中删除图片
typedef struct tagTDCSAdpWbDelPicOperInfo
{
	s8 					m_achTabId[MT_STR_LEN_64+1];            // 白板tab id（guid）
	u32 				m_dwSubPageId;   	// 子页id

	u32					m_dwGraphsCount;
	s8					m_achGraphsId[MT_DCS_POINT_MAX+1][MT_STR_LEN_128+1];

	tagTDCSAdpWbDelPicOperInfo() { memset(this, 0, sizeof(tagTDCSAdpWbDelPicOperInfo)); }

}*PTDCSAdpWbDelPicOperInfo, TDCSAdpWbDelPicOperInfo;



typedef struct tagTDCSAdpImageUrl
{
	s8			m_achConfE164[MT_STR_LEN_64+1];
	s8 			m_achTabId[MT_STR_LEN_64+1];
	u32 		m_dwWbPageId;
	s8			m_achWbPicentityId[MT_STR_LEN_64+1];		// 图片ID

	s8			m_achPicUrl[MT_STR_LEN_256+1];

	tagTDCSAdpImageUrl() { memset(this, 0, sizeof(tagTDCSAdpImageUrl)); }

}*PTDCSAdpImageUrl, TDCSAdpImageUrl;


typedef struct tagTDCSAdpConnectResult
{
	BOOL32		m_bSuccess;
	EmDcsAdpConnectErrCode		m_emErrorCode;

	tagTDCSAdpConnectResult() { memset(this, 0, sizeof(tagTDCSAdpConnectResult)); }

}*PTDCSAdpConnectResult, TDCSAdpConnectResult;

typedef struct tagTDCSAdpRejectJoinConf
{
	s8 			m_achConfE164[MT_STR_LEN_64+1];
	EmDcsAdpRejectJoinConfCode  		m_emReason;

	tagTDCSAdpRejectJoinConf() { memset(this, 0, sizeof(tagTDCSAdpRejectJoinConf)); }

}*PTDCSAdpRejectJoinConf, TDCSAdpRejectJoinConf;

// typedef struct tagTDCSAdpFileLoadResult
// {
//     BOOL32		m_bSuccess;
//     BOOL32		m_bElementFile;
//     s8          m_achFilePathName[MT_STR_LEN_512+1];
// 	s8			m_achWbPicentityId[MT_STR_LEN_64+1];
// 	s8			m_achTabid[MT_STR_LEN_64+1]; 
//     tagTDCSAdpFileLoadResult() { memset( this, 0, sizeof( tagTDCSAdpFileLoadResult ) ); }
// }*PTDCSAdpFileLoadResult, TDCSAdpFileLoadResult;

typedef struct tagTDCSAdpFileInfo
{
	s8		m_achFilePathName[MT_STR_LEN_512+1];
	s8		m_achWbPicentityId[MT_STR_LEN_64+1];			// 如果是图片，则会有pic id，否则为空
	s8		m_achTabid[MT_STR_LEN_64+1];
    BOOL32 m_bElementCacheFile; ///< 是否为图元缓存文件

	tagTDCSAdpFileInfo() { memset( this, 0, sizeof( tagTDCSAdpFileInfo ) ); }

}*PTDCSAdpFileInfo, TDCSAdpFileInfo;



#endif  // _MTDCSSTRUCT_H_
