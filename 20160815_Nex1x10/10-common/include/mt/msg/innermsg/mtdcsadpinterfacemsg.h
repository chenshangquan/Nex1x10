#ifndef _DCS_ADP_API_H_
#define _DCS_ADP_API_H_

#include "mtospmsgid.h"
#include "mtdcsadpstructmsg.h"

#ifdef  __cplusplus
extern "C" {
#endif


#if (defined(WIN32) || defined(_WIN32) ) && !defined(DCS_ADP_STATICLIB)

#if defined(BUILDING_LIBDCS)
#define DCS_ADP_API  __declspec(dllexport)
#else
#define DCS_ADP_API  __declspec(dllimport)
#endif

#else  // 其他平台的，或者是静态链接

#define DCS_ADP_API

#endif
}

typedef void (*pfDcsAdpCallBack)( u32 dwEvent, u8 *pbyMainBuf, u32 dwMainBufLen, u8 *pbySubBuf, u32 dwSubBufLen);

/** ************************************************************
	* 
	* @brief    保持与数字会议服务器之间的心跳连接
	*
	* @param	TDCSAdpApsLoginParam        
	* @return	u32
	* @note     保持与数字会议服务器之间的心跳连接
	*			对应返回消息：Ev_DcsAdp_LoginSrv_KeepAlive_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpKeepAlive(TDCSAdpApsLoginParam* ptLoginParam);


/** ************************************************************
	* 
	* @brief    关闭当前会议链路
	*
	* @param	        
	* @return	u32
	* @note     无
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpCloseConfSession();


/** ************************************************************
	* 
	* @brief    初始化DcsAdp模块
	*
	* @param	pfDcsAdpCallBack        
	* @return	u32
	* @note     初始化DcsAdp模块,以及下层websocket的初始化，并设置回调函数
	*
	************************************************************* */
u32 DCS_ADP_API DcsAdpInit( pfDcsAdpCallBack pfCallBack );


/** ************************************************************
	* 
	* @brief    与服务器建链
	*
	* @param	s8，长度MT_STR_LEN_128+1     	服务器IP地址
	            u32 							服务器端口
	* @return	u32
	* @note     与服务器建链（每一次注册，入会，都需要重新建链）
	*
	************************************************************* */
u32 DCS_ADP_API DcsAdpConnectWebSocket(s8* pchIp, u32 dwPortm, EmDcsAdpConnectType emType);


/** ************************************************************
	* 
	* @brief    绘图操作：点相关
	*
	* @param	TDCSAdpOperReq     				绘图操作类型
	            TDCSAdpWbPoint 					点相关结构
	* @return	u32
	* @note     绘图操作：点相关
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbPoint* ptPoint);


/** ************************************************************
	* 
	* @brief    绘图操作：标识图元
	*
	* @param	TDCSAdpOperReq     				绘图操作类型
	            TDCSAdpWbEntity 				标识图元，其中的m_achEntityId，填写为GUID
	* @return	u32
	* @note     绘图操作：标识图元
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbEntity* ptEntity);


/** ************************************************************
	* 
	* @brief    绘图操作：线相关
	*
	* @param	TDCSAdpOperReq     				绘图操作类型
	            TDCSAdpWbLine 					线相关结构
	* @return	u32
	* @note     绘图操作：线相关
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbLine* ptLine);


/** ************************************************************
	* 
	* @brief    绘图操作：圆相关
	*
	* @param	TDCSAdpOperReq     				绘图操作类型
	            TDCSAdpWbCircle 				圆相关结构
	* @return	u32
	* @note     绘图操作：圆相关
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbCircle* ptCircle);


/** ************************************************************
	* 
	* @brief    绘图操作：铅笔相关
	*
	* @param	TDCSAdpOperReq     				绘图操作类型
	            TDCSAdpWbPencil 				铅笔相关结构
	* @return	u32
	* @note     绘图操作：铅笔相关
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbPencil* ptPencil);


/** ************************************************************
	* 
	* @brief    绘图操作：彩笔相关
	*
	* @param	TDCSAdpOperReq     				绘图操作类型
	            TDCSAdpWbColorPen 				彩笔相关结构
	* @return	u32
	* @note     绘图操作：彩笔相关
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbColorPen* ptColorPen);


/** ************************************************************
	* 
	* @brief    绘图操作：图片图元相关
	*
	* @param	TDCSAdpOperReq     				绘图操作类型
	            TDCSAdpWbImage 					图片图元相关结构
	* @return	u32
	* @note     绘图操作：图片图元相关
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbImage* ptImage);


/** ************************************************************
	* 
	* @brief    绘图操作：线绘图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
	*
	* @param	TDCSOperReq     				绘图操作类型
	            TDCSWbLineOperInfo 			线绘图操作详细信息相关结构
	* @return	u32
	* @note     绘图操作：线绘图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbLineOperInfo* ptLineOperInfo);


/** ************************************************************
	* 
	* @brief    绘图操作：圆绘图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
	*
	* @param	TDCSOperReq     				绘图操作类型
	            TDCSWbCircleOperInfo 		圆绘图操作详细信息相关结构
	* @return	u32
	* @note     绘图操作：圆绘图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbCircleOperInfo* ptCircleOperInfo);



/** ************************************************************
	* 
	* @brief    矩形操作：矩形绘图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
	*
	* @param	TDCSOperReq     				绘图操作类型
	            TDCSWbRectangleOperInfo 		矩形绘图操作详细信息相关结构
	* @return	u32
	* @note     绘图操作：圆绘图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbRectangleOperInfo* ptRectangleOperInfo);


/** ************************************************************
	* 
	* @brief    绘图操作：铅笔图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
	*
	* @param	TDCSOperReq     				绘图操作类型
	            TDCSWbPencilOperInfo 		铅笔绘图操作详细信息相关结构
	* @return	u32
	* @note     绘图操作：铅笔绘图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbPencilOperInfo* ptPencilOperInfo);


/** ************************************************************
	* 
	* @brief    绘图操作：彩笔图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
	*
	* @param	TDCSOperReq     				绘图操作类型
	            TDCSWbColorPenOperInfo 		彩笔绘图操作详细信息相关结构
	* @return	u32
	* @note     绘图操作：彩笔绘图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbColorPenOperInfo *ptColorPenOperInfo);


/** ************************************************************
	* 
	* @brief    绘图操作：图片图元绘图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
	*
	* @param	TDCSOperReq     				绘图操作类型
	            TDCSWbImageOperInfo 			图片图元绘图操作详细信息相关结构
	* @return	u32
	* @note     绘图操作：图片图元绘图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbImageOperInfo *ptImageOperInfo);


/** ************************************************************
	* 
	* @brief    标记当前操作文档的tab页和subpage
	*
	* @param	TDCSAdpOperReq     				绘图操作类型
	            TDCSAdpWbTabPageIdInfo 			标记当前操作文档的tab页和subpage
	* @return	u32
	* @note     标记当前操作文档的tab页和subpage
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbTabPageIdInfo *ptTabPageIdInfo);


/** ************************************************************
	* 
	* @brief    删除tab页携带的信息
	*
	* @param	TDCSAdpOperReq     				绘图操作类型
	            TDCSAdpWbRemovePageIdInfo 		删除tab页携带的信息
	* @return	u32
	* @note     删除tab页携带的信息
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbRemovePageIdInfo *ptRemovePageIdInfo);


/** ************************************************************
	* 
	* @brief    白板页信息
	*
	* @param	TDCSAdpOperReq     				绘图操作类型
	            TDCSAdpWbTabPageInfo 			白板页信息
	* @return	u32
	* @note     白板页信息，在创建白板、更新白板信息等时候使用
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbTabPageInfo *ptTabPageInfo);


/** ************************************************************
	* 
	* @brief    白板中添加子页信息
	*
	* @param	TDCSOperReq     					绘图操作类型
	            TDCSWbAddSubPageInfo	 			添加白板页信息
	* @return	u32
	* @note     白板中添加子页信息，打开文档时，根据文档的总页数在当前白板中添加多个子页
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbAddSubPageInfo *ptAddSubPageInfo);

/** ************************************************************
	* 
	* @brief    切换白板页信息
	*
	* @param	TDCSAdpOperReq     					绘图操作类型
	            TDCSAdpWbSwitchPageInfo 			切换白板页信息
	* @return	u32
	* @note     切换白板页信息，
	*               1)在当前白板中从一个子页切换到另一子页，即前后翻页，或者翻到指定的页面；
	* 				2)切换到另一个白板中
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbSwitchPageInfo *ptSwitchPageInfo);

/** ************************************************************
	* 
	* @brief    客户端给服务器发送请求目标页图片请求
	*
	* @param	TDCSAdpOperReq     					绘图操作类型
	            TDCSAdpWbReqPageImage 				请求目标页图片信息
	* @return	u32
	* @note     客户端给服务器发送请求目标页图片请求
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbReqPageImage *ptReqPageImage);


/** ************************************************************
	* 
	* @brief    矩形擦除
	*
	* @param	TDCSOperReq     					绘图操作类型
	            TDCSWbEraseOperInfo 				矩形擦除信息
	* @return	u32
	* @note     矩形擦除
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbEraseOperInfo *ptEraseOperInfo);


/** ************************************************************
	* 
	* @brief    放大/缩小、横向/纵向自适应
	*
	* @param	TDCSOperReq     					绘图操作类型
	            TDCSWbZoomInfo	 					放大/缩小、横向/纵向信息
	* @return	u32
	* @note     放大/缩小、横向/纵向自适应
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbZoomInfo *ptZoomInfo);


/** ************************************************************
	* 
	* @brief    发送图片文件的信息
	*
	* @param	TDCSAdpOperReq     					绘图操作类型
	            TDCSAdpWbSendImgFileInfo			发送图片文件的信息
	* @return	u32
	* @note     发送图片文件的信息
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbSendImgFileInfo *ptSendImgFileInfo);


/** ************************************************************
	* 
	* @brief    撤销与反撤销
	*
	* @param	EmDcsAdpOper						redo或是undo
				TDCSOperReq     					绘图操作类型
	            TDCSWbTabPageIdInfo					标记当前操作文档的tab页和subpage
	* @return	u32
	* @note     撤销与反撤销
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(EmDcsAdpOper emOper, mt::TDCSOperReq *ptOper, mt::TDCSWbTabPageIdInfo *ptTabPageIdInfo);

/** ************************************************************
	* 
	* @brief    左旋转与右旋转
	*
	* @param	EmDcsAdpOper						rotateleft或是rotateright
				TDCSOperReq     					绘图操作类型
	            TString								table id号
	* @return	u32
	* @note     左旋转与右旋转
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(EmDcsAdpOper emOper, mt::TDCSOperReq *ptOper, mt::TString *ptTabId);

/** ************************************************************
	* 
	* @brief    清屏
	*
	* @param	EmDcsAdpOper						emWbClearScreen
				TDCSAdpOperReq     					绘图操作类型
	* @return	u32
	* @note     左旋转与右旋转
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(EmDcsAdpOper emOper, mt::TDCSOperReq *ptOper);


/** ************************************************************
	* 
	* @brief    滚动屏幕（抓手）操作scrollscreen，携带数据
	*
	* @param	TDCSOperReq     						请求信息
				TDCSScrollScreenInfo					滚动屏幕信息
	* @return	u32
	* @note     滚动屏幕（抓手）操作scrollscreen，携带数据
	*			
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSScrollScreenInfo *ptScrollScreenInfo);


/** ************************************************************
	* 
	* @brief    1. 全屏显示所有内容
	*			   因为网呈画布是无限大，所以画的超出原有画布大小的时候，有一个全屏显示所有功能，缩小比例，全屏显示所有内容
	*			2. 100%比例显示
	*			   手势缩放，需要一个参考点；TL与网呈需要相互转化参考点
	*
	* @param	EmDcsAdpOper     						是种类1还是种类2
	*			TDCSOperReq							操作类型
	*			TDCSWbDisPlayInfo						显示内容
	* @return	u32
	* @note     
	*			
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(EmDcsAdpOper emOper, TDCSAdpOperReq* ptOperReq, TDCSAdpWbDisPlayInfo* ptTDCSAdpDisPlayInfo);
u32 DCS_ADP_API OnDcsAdpWbOper(EmDcsAdpOper emOper, mt::TDCSOperReq *ptOper, mt::TDCSWbDisPlayInfo *ptDCSWbDisPlayInfo);


/** ************************************************************
	* 
	* @brief    区域擦除
	*
	* @param	TDCSOperReq     						请求信息
				TDCSWbReginEraseOperInfo				区域擦除信息
	* @return	u32
	* @note     区域擦除
	*			
	************************************************************* */
// u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbReginEraseOperInfo* ptReginEraseOperInfo);
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbReginEraseOperInfo *ptDCSWbReginEraseOperInfo);


/** ************************************************************
	* 
	* @brief    插入图片
	*
	* @param	TDCSOperReq     						请求信息
				TDCSWbInsertPicOperInfo				插入图片信息
	* @return	u32
	* @note     插入图片
	*			
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbInsertPicOperInfo* ptInsertPicOperInfo);
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbInsertPicOperInfo *ptDCSWbInsertPicOperInfo);


/** ************************************************************
	* 
	* @brief    1. 选中图片缩放
	*			2. 选中图片旋转
	*			3. 选中图片拖动
	*
	* @param	EmDcsAdpOper     						是种类1还是种类2，种类3
	*			TDCSOperReq							操作类型
	*			TDCSWbPitchPicOperInfo				操作选中图片
	* @return	u32
	* @note     
	*			
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(EmDcsAdpOper emOper, TDCSAdpOperReq* ptOperReq, TDCSAdpWbPitchPicOperInfo* ptPitchPicOperInfo);
u32 DCS_ADP_API OnDcsAdpWbOper(EmDcsAdpOper emOper, mt::TDCSOperReq *ptOper, mt::TDCSWbPitchPicOperInfo *ptDCSWbPitchPicOperInfo);


/** ************************************************************
	* 
	* @brief    选中图片删除
	*
	* @param	TDCSOperReq     						请求信息
				TDCSWbDelPicOperInfo					选中图片删除
	* @return	u32
	* @note     选中图片删除
	*			
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbDelPicOperInfo* ptDelPicOperInfo);
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper,  mt::TDCSWbDelPicOperInfo *ptDCSWbDelPicOperInfo);


/** ************************************************************
	* 
	* @brief    向服务器请求切换白板
	*
	* @param	TDCSAdpSwitchReq     					请求信息
	* @return	u32
	* @note     向服务器请求切换白板
	*			对应返回消息：Ev_DcsAdp_Switch_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpSwitchReq(TDCSAdpSwitchReq* ptSwitch);


/** ************************************************************
	* 
	* @brief    向服务器获取对应白板信息
	*
	* @param	s8 长度MT_STR_LEN_32  					会议E164号
	            u32 									白板索引
	* @return	u32
	* @note     向服务器获取对应白板信息
	*			对应返回消息：Ev_DcsAdp_GetCurWhiteBoard_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpGetWhiteBoardReq(s8* pachConfE164, s8* pachWbIndex);


/** ************************************************************
	* 
	* @brief    向服务器获取当前白板信息
	*
	* @param	s8 长度MT_STR_LEN_32  					会议E164号
	* @return	u32
	* @note     向服务器获取对应白板信息
	*			对应返回消息：Ev_DcsAdp_GetCurWhiteBoard_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpGetCurWhiteBoardReq(s8* pachConfE164);


/** ************************************************************
	* 
	* @brief    向服务器删除所有白板信息
	*
	* @param	s8 长度MT_STR_LEN_32  					会议E164号
	* @return	u32
	* @note     向服务器获取对应白板信息
	*			对应返回消息：Ev_DcsAdp_DelAllWhiteBoard_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpDelAllWhiteBoardReq(s8* pachConfE164);



/** ************************************************************
	* 
	* @brief    向服务器获取所有白板信息
	*
	* @param	s8 长度MT_STR_LEN_32  					会议E164号
	* @return	u32
	* @note     向服务器获取所有白板信息
	*			对应返回消息：Ev_DcsAdp_GetAllWhiteBoard_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpGetAllWhiteBoardReq(s8* pachConfE164);


/** ************************************************************
	* 
	* @brief    向服务器删除对应白板信息
	*
	* @param	s8 长度MT_STR_LEN_32  					会议E164号
				u32 									白板索引
	* @return	u32
	* @note     向服务器删除对应白板信息
	*			对应返回消息：Ev_DcsAdp_DelWhiteBoard_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpDelWhiteBoardReq(s8* pachConfE164, s8* pachWbIndex);


/** ************************************************************
	* 
	* @brief    向服务器创建白板信息
	*
	* @param	TDCSAdpNewWhiteBoard  					新白板信息
	* @return	u32
	* @note     向服务器创建白板信息
	*			对应返回消息：Ev_DcsAdp_NewWhiteBoard_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpNewWhiteBoardReq(TDCSAdpNewWhiteBoard* ptNewBoard);


/** ************************************************************
	* 
	* @brief    向服务器请求用户列表信息
	*
	* @param	s8 长度MT_STR_LEN_32  					会议E164号
	* @return	u32
	* @note     向服务器请求用户列表信息
	*			对应返回消息：Ev_DcsAdp_GetUserList_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpGetUserListReq(s8* pachConfE164);


/** ************************************************************
	* 
	* @brief    向服务器请求取消协作权
	*
	* @param	s8 长度MT_STR_LEN_32  					会议E164号
	* @return	u32
	* @note     向服务器请求取消协作权
	*			对应返回消息：Ev_DcsAdp_CancelOper_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpCancelOperReq(s8* pachConfE164);


/** ************************************************************
	* 
	* @brief    向服务器申请协作权
	*
	* @param	s8 长度MT_STR_LEN_32  					会议E164号
	* @return	u32
	* @note     向服务器申请协作权
	*			对应返回消息：Ev_DcsAdp_ApplyOper_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpApplyOperReq(s8* pachConfE164);


/** ************************************************************
	* 
	* @brief    向服务器设置与会方角色
	*
	* @param	TDCSAdpSetUserRole  					与会方角色
	* @return	u32
	* @note     向服务器设置与会方角色
	*			对应返回消息：Ev_DcsAdp_SetUserRole_Rsp
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpSetUserRoleReq(TDCSAdpSetUserRole *ptUserInfo);


/** ************************************************************
	* 
	* @brief    向服务器设置数值会议信息
	*
	* @param	TDCSAdpConfInfo  						会议信息
	* @return	u32
	* @note     向服务器设置数值会议信息
	*			对应返回消息：Ev_DcsAdp_SetConfInfo_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpSetConfInfoReq(TDCSAdpConfInfo *ptConfInfo);


/** ************************************************************
	* 
	* @brief    向服务器删除与会方
	*
	* @param	TDCSAdpMemberInfo  						与会方信息
	* @return	u32
	* @note     向服务器删除与会方
	*			对应返回消息：Ev_DcsAdp_DelMember_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpDelMemberReq(TDCSAdpMemberInfo *ptMemberInfo);


/** ************************************************************
	* 
	* @brief    向服务器添加与会方
	*
	* @param	TDCSAdpMemberInfo  						与会方信息
	* @return	u32
	* @note     向服务器添加与会方
	*			对应返回消息：Ev_DcsAdp_AddMember_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpAddMemberReq(TDCSAdpMemberInfo *ptMemberInfo);


/** ************************************************************
	* 
	* @brief    向服务器结会请求
	*
	* @param	s8 长度MT_STR_LEN_32  					会议E164号
	* @return	u32
	* @note     向服务器结会请求
	*			对应返回消息：Ev_DcsAdp_ReleaseConf_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpReleaseConfReq(s8* pachConfE164);


/** ************************************************************
	* 
	* @brief    退会请求
	*
	* @param	s8 长度MT_STR_LEN_32  					会议E164号
				u32				0: 同时操作视频、数据，请携带0（视频会议也退出，白板会议也退出->为了解决，如果主动退出视频会议，白板会议服务器就不再呼叫该终端入会，下一次的时候）
								1: 只操作数据协作，请携带1（视频会议还在，只是推出白板会议）
	* @return	u32
	* @note     退会请求
	*			对应返回消息：Ev_DcsAdp_QuitConf_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpQuitConfReq(s8* pachConfE164, u32 dwForceFlag);


/** ************************************************************
	* 
	* @brief    入会请求
	*
	* @param	s8 长度MT_STR_LEN_32  					会议E164号
	* @return	u32
	* @note     入会请求
	*			对应返回消息：Ev_DcsAdp_JoinConf_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpJoinConfReq(s8* pachConfE164);



/** ************************************************************
	* 
	* @brief    当前终端拒绝入会
	*
	* @param	TDCSAdpRejectJoinConf  					拒绝入会结构
	* @return	u32
	* @note     入会请求
	*			对应返回消息：无
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpRejectJoinConfCmd(TDCSAdpRejectJoinConf *ptRejectJoinConf);


/** ************************************************************
	* 
	* @brief    创建数字会议请求
	*
	* @param	TDCSAdpCreateP2PConf  					创建数字会议
	* @return	u32
	* @note     创建数字会议请求
	*			对应返回消息：Ev_DcsAdp_DcsCreateConf_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpCreateConfReq(TDCSAdpCreateConf *ptCreateConf);


/** ************************************************************
	* 
	* @brief    登出数字会议服务器
	*
	* @param	暂无
	* @return	u32
	* @note     登出数字会议服务器
	*			对应返回消息：Ev_DcsAdp_DcsLogout_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpLogoutReq();


/** ************************************************************
	* 
	* @brief    登录数字会议服务器
	*
	* @param	TDCSAdpApsLoginParam 			登录结构
	* @return	u32
	* @note     登录数字会议服务器
	*			对应返回消息：Ev_DcsAdp_LoginSrv_Rsp
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpLoginSrvReq(EmDcsAdpType emType, TDCSAdpApsLoginParam* ptLoginParam);

/** ************************************************************
	* 
	* @brief    添加协作方请求
	*
	* @param	TDCSAdpOperator 			协作方信息
	* @return	u32
	* @note     添加协作方请求
	*			对应返回消息：Ev_DcsAdp_AddOperator_Rsp
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpAddOperatorReq(TDCSAdpOperator* ptAdpAddOperReq);


/** ************************************************************
	* 
	* @brief    删除协作方请求
	*
	* @param	TDCSAdpOperator 			协作方信息
	* @return	u32
	* @note     删除协作方请求
	*			对应返回消息：Ev_DcsAdp_DelOperator_Rsp
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpDelOperatorReq(TDCSAdpOperator* ptAdpAddOperReq);


/** ************************************************************
	* 
	* @brief    查询会议地址
	*
	* @param	s8 			会议E164	号
	* @return	u32
	* @note     查询会议地址
	*			对应返回消息：Ev_DcsAdp_GetConfAddr_Rsp
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpGetConfAddrReq(s8* pachConfE164);


/** ************************************************************
	* 
	* @brief    获取图片下载地址请求
	*
	* @param	TDCSAdpImageUrl 			参数
	* @return	u32
	* @note     获取图片下载地址请求
	*			对应返回消息：Ev_DcsAdp_DownloadImage_Rsp
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpDownloadImageReq(TDCSAdpImageUrl* ptImageUrl);


/** ************************************************************
	* 
	* @brief    获取图片上传地址请求
	*
	* @param	TDCSAdpImageUrl 			参数
	* @return	u32
	* @note     获取图片上传地址请求
	*			对应返回消息：Ev_DcsAdp_UploadImage_Rsp
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpUploadImageReq(TDCSAdpImageUrl* ptImageUrl);



/** ************************************************************
	* 
	* @brief    拒绝申请协作方
	*
	* @param	TDCSAdpOperator 			参数
	* @return	u32
	* @note     拒绝申请协作方
	*			对应返回消息：无
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpRejectOperatorCmd(TDCSAdpOperator* ptOperator);


/** ************************************************************
	* 
	* @brief    上传文件
	*
	* @param	pchUploadUrl 			上传URL
    * @param	pchFilePathName 		文件信息
	* @return	u32
	* @note     上传文件
	*			对应返回消息：Ev_DcsAdp_UploadFile_Ntf
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpUploadFileCmd(const s8* pchUploadUrl, TDCSAdpFileInfo& tFileInfo/*const s8* pchFilePathName*/);

/** ************************************************************
	* 
	* @brief    下载文件
	*
	* @param	pchDownloadUrl 		文件URL
    * @param	pchFilePathName 		文件信息
	* @return	u32
	* @note     下载文件
	*			对应返回消息：Ev_DcsAdp_DownloadFile_Ntf
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpDownloadFileReq(const s8* pchDownloadUrl, TDCSAdpFileInfo& tFileInfo/*const s8* pchFilePathName*/);
#endif
















