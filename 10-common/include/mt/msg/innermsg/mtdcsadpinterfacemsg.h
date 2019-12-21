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

#else  // ����ƽ̨�ģ������Ǿ�̬����

#define DCS_ADP_API

#endif
}

typedef void (*pfDcsAdpCallBack)( u32 dwEvent, u8 *pbyMainBuf, u32 dwMainBufLen, u8 *pbySubBuf, u32 dwSubBufLen);

/** ************************************************************
	* 
	* @brief    ���������ֻ��������֮�����������
	*
	* @param	TDCSAdpApsLoginParam        
	* @return	u32
	* @note     ���������ֻ��������֮�����������
	*			��Ӧ������Ϣ��Ev_DcsAdp_LoginSrv_KeepAlive_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpKeepAlive(TDCSAdpApsLoginParam* ptLoginParam);


/** ************************************************************
	* 
	* @brief    �رյ�ǰ������·
	*
	* @param	        
	* @return	u32
	* @note     ��
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpCloseConfSession();


/** ************************************************************
	* 
	* @brief    ��ʼ��DcsAdpģ��
	*
	* @param	pfDcsAdpCallBack        
	* @return	u32
	* @note     ��ʼ��DcsAdpģ��,�Լ��²�websocket�ĳ�ʼ���������ûص�����
	*
	************************************************************* */
u32 DCS_ADP_API DcsAdpInit( pfDcsAdpCallBack pfCallBack );


/** ************************************************************
	* 
	* @brief    �����������
	*
	* @param	s8������MT_STR_LEN_128+1     	������IP��ַ
	            u32 							�������˿�
	* @return	u32
	* @note     �������������ÿһ��ע�ᣬ��ᣬ����Ҫ���½�����
	*
	************************************************************* */
u32 DCS_ADP_API DcsAdpConnectWebSocket(s8* pchIp, u32 dwPortm, EmDcsAdpConnectType emType);


/** ************************************************************
	* 
	* @brief    ��ͼ�����������
	*
	* @param	TDCSAdpOperReq     				��ͼ��������
	            TDCSAdpWbPoint 					����ؽṹ
	* @return	u32
	* @note     ��ͼ�����������
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbPoint* ptPoint);


/** ************************************************************
	* 
	* @brief    ��ͼ��������ʶͼԪ
	*
	* @param	TDCSAdpOperReq     				��ͼ��������
	            TDCSAdpWbEntity 				��ʶͼԪ�����е�m_achEntityId����дΪGUID
	* @return	u32
	* @note     ��ͼ��������ʶͼԪ
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbEntity* ptEntity);


/** ************************************************************
	* 
	* @brief    ��ͼ�����������
	*
	* @param	TDCSAdpOperReq     				��ͼ��������
	            TDCSAdpWbLine 					����ؽṹ
	* @return	u32
	* @note     ��ͼ�����������
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbLine* ptLine);


/** ************************************************************
	* 
	* @brief    ��ͼ������Բ���
	*
	* @param	TDCSAdpOperReq     				��ͼ��������
	            TDCSAdpWbCircle 				Բ��ؽṹ
	* @return	u32
	* @note     ��ͼ������Բ���
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbCircle* ptCircle);


/** ************************************************************
	* 
	* @brief    ��ͼ������Ǧ�����
	*
	* @param	TDCSAdpOperReq     				��ͼ��������
	            TDCSAdpWbPencil 				Ǧ����ؽṹ
	* @return	u32
	* @note     ��ͼ������Ǧ�����
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbPencil* ptPencil);


/** ************************************************************
	* 
	* @brief    ��ͼ�������ʱ����
	*
	* @param	TDCSAdpOperReq     				��ͼ��������
	            TDCSAdpWbColorPen 				�ʱ���ؽṹ
	* @return	u32
	* @note     ��ͼ�������ʱ����
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbColorPen* ptColorPen);


/** ************************************************************
	* 
	* @brief    ��ͼ������ͼƬͼԪ���
	*
	* @param	TDCSAdpOperReq     				��ͼ��������
	            TDCSAdpWbImage 					ͼƬͼԪ��ؽṹ
	* @return	u32
	* @note     ��ͼ������ͼƬͼԪ���
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbImage* ptImage);


/** ************************************************************
	* 
	* @brief    ��ͼ�������߻�ͼ������ϸ��Ϣ���Ѿ��װ�����У�ÿ����һ�ζ�Ӧ�Ĳ�����Ϣ��
	*
	* @param	TDCSOperReq     				��ͼ��������
	            TDCSWbLineOperInfo 			�߻�ͼ������ϸ��Ϣ��ؽṹ
	* @return	u32
	* @note     ��ͼ�������߻�ͼ������ϸ��Ϣ���Ѿ��װ�����У�ÿ����һ�ζ�Ӧ�Ĳ�����Ϣ��
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbLineOperInfo* ptLineOperInfo);


/** ************************************************************
	* 
	* @brief    ��ͼ������Բ��ͼ������ϸ��Ϣ���Ѿ��װ�����У�ÿ����һ�ζ�Ӧ�Ĳ�����Ϣ��
	*
	* @param	TDCSOperReq     				��ͼ��������
	            TDCSWbCircleOperInfo 		Բ��ͼ������ϸ��Ϣ��ؽṹ
	* @return	u32
	* @note     ��ͼ������Բ��ͼ������ϸ��Ϣ���Ѿ��װ�����У�ÿ����һ�ζ�Ӧ�Ĳ�����Ϣ��
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbCircleOperInfo* ptCircleOperInfo);



/** ************************************************************
	* 
	* @brief    ���β��������λ�ͼ������ϸ��Ϣ���Ѿ��װ�����У�ÿ����һ�ζ�Ӧ�Ĳ�����Ϣ��
	*
	* @param	TDCSOperReq     				��ͼ��������
	            TDCSWbRectangleOperInfo 		���λ�ͼ������ϸ��Ϣ��ؽṹ
	* @return	u32
	* @note     ��ͼ������Բ��ͼ������ϸ��Ϣ���Ѿ��װ�����У�ÿ����һ�ζ�Ӧ�Ĳ�����Ϣ��
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbRectangleOperInfo* ptRectangleOperInfo);


/** ************************************************************
	* 
	* @brief    ��ͼ������Ǧ��ͼ������ϸ��Ϣ���Ѿ��װ�����У�ÿ����һ�ζ�Ӧ�Ĳ�����Ϣ��
	*
	* @param	TDCSOperReq     				��ͼ��������
	            TDCSWbPencilOperInfo 		Ǧ�ʻ�ͼ������ϸ��Ϣ��ؽṹ
	* @return	u32
	* @note     ��ͼ������Ǧ�ʻ�ͼ������ϸ��Ϣ���Ѿ��װ�����У�ÿ����һ�ζ�Ӧ�Ĳ�����Ϣ��
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbPencilOperInfo* ptPencilOperInfo);


/** ************************************************************
	* 
	* @brief    ��ͼ�������ʱ�ͼ������ϸ��Ϣ���Ѿ��װ�����У�ÿ����һ�ζ�Ӧ�Ĳ�����Ϣ��
	*
	* @param	TDCSOperReq     				��ͼ��������
	            TDCSWbColorPenOperInfo 		�ʱʻ�ͼ������ϸ��Ϣ��ؽṹ
	* @return	u32
	* @note     ��ͼ�������ʱʻ�ͼ������ϸ��Ϣ���Ѿ��װ�����У�ÿ����һ�ζ�Ӧ�Ĳ�����Ϣ��
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbColorPenOperInfo *ptColorPenOperInfo);


/** ************************************************************
	* 
	* @brief    ��ͼ������ͼƬͼԪ��ͼ������ϸ��Ϣ���Ѿ��װ�����У�ÿ����һ�ζ�Ӧ�Ĳ�����Ϣ��
	*
	* @param	TDCSOperReq     				��ͼ��������
	            TDCSWbImageOperInfo 			ͼƬͼԪ��ͼ������ϸ��Ϣ��ؽṹ
	* @return	u32
	* @note     ��ͼ������ͼƬͼԪ��ͼ������ϸ��Ϣ���Ѿ��װ�����У�ÿ����һ�ζ�Ӧ�Ĳ�����Ϣ��
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbImageOperInfo *ptImageOperInfo);


/** ************************************************************
	* 
	* @brief    ��ǵ�ǰ�����ĵ���tabҳ��subpage
	*
	* @param	TDCSAdpOperReq     				��ͼ��������
	            TDCSAdpWbTabPageIdInfo 			��ǵ�ǰ�����ĵ���tabҳ��subpage
	* @return	u32
	* @note     ��ǵ�ǰ�����ĵ���tabҳ��subpage
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbTabPageIdInfo *ptTabPageIdInfo);


/** ************************************************************
	* 
	* @brief    ɾ��tabҳЯ������Ϣ
	*
	* @param	TDCSAdpOperReq     				��ͼ��������
	            TDCSAdpWbRemovePageIdInfo 		ɾ��tabҳЯ������Ϣ
	* @return	u32
	* @note     ɾ��tabҳЯ������Ϣ
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbRemovePageIdInfo *ptRemovePageIdInfo);


/** ************************************************************
	* 
	* @brief    �װ�ҳ��Ϣ
	*
	* @param	TDCSAdpOperReq     				��ͼ��������
	            TDCSAdpWbTabPageInfo 			�װ�ҳ��Ϣ
	* @return	u32
	* @note     �װ�ҳ��Ϣ���ڴ����װ塢���°װ���Ϣ��ʱ��ʹ��
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbTabPageInfo *ptTabPageInfo);


/** ************************************************************
	* 
	* @brief    �װ��������ҳ��Ϣ
	*
	* @param	TDCSOperReq     					��ͼ��������
	            TDCSWbAddSubPageInfo	 			��Ӱװ�ҳ��Ϣ
	* @return	u32
	* @note     �װ��������ҳ��Ϣ�����ĵ�ʱ�������ĵ�����ҳ���ڵ�ǰ�װ�����Ӷ����ҳ
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbAddSubPageInfo *ptAddSubPageInfo);

/** ************************************************************
	* 
	* @brief    �л��װ�ҳ��Ϣ
	*
	* @param	TDCSAdpOperReq     					��ͼ��������
	            TDCSAdpWbSwitchPageInfo 			�л��װ�ҳ��Ϣ
	* @return	u32
	* @note     �л��װ�ҳ��Ϣ��
	*               1)�ڵ�ǰ�װ��д�һ����ҳ�л�����һ��ҳ����ǰ��ҳ�����߷���ָ����ҳ�棻
	* 				2)�л�����һ���װ���
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbSwitchPageInfo *ptSwitchPageInfo);

/** ************************************************************
	* 
	* @brief    �ͻ��˸���������������Ŀ��ҳͼƬ����
	*
	* @param	TDCSAdpOperReq     					��ͼ��������
	            TDCSAdpWbReqPageImage 				����Ŀ��ҳͼƬ��Ϣ
	* @return	u32
	* @note     �ͻ��˸���������������Ŀ��ҳͼƬ����
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbReqPageImage *ptReqPageImage);


/** ************************************************************
	* 
	* @brief    ���β���
	*
	* @param	TDCSOperReq     					��ͼ��������
	            TDCSWbEraseOperInfo 				���β�����Ϣ
	* @return	u32
	* @note     ���β���
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbEraseOperInfo *ptEraseOperInfo);


/** ************************************************************
	* 
	* @brief    �Ŵ�/��С������/��������Ӧ
	*
	* @param	TDCSOperReq     					��ͼ��������
	            TDCSWbZoomInfo	 					�Ŵ�/��С������/������Ϣ
	* @return	u32
	* @note     �Ŵ�/��С������/��������Ӧ
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbZoomInfo *ptZoomInfo);


/** ************************************************************
	* 
	* @brief    ����ͼƬ�ļ�����Ϣ
	*
	* @param	TDCSAdpOperReq     					��ͼ��������
	            TDCSAdpWbSendImgFileInfo			����ͼƬ�ļ�����Ϣ
	* @return	u32
	* @note     ����ͼƬ�ļ�����Ϣ
	*
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbSendImgFileInfo *ptSendImgFileInfo);


/** ************************************************************
	* 
	* @brief    �����뷴����
	*
	* @param	EmDcsAdpOper						redo����undo
				TDCSOperReq     					��ͼ��������
	            TDCSWbTabPageIdInfo					��ǵ�ǰ�����ĵ���tabҳ��subpage
	* @return	u32
	* @note     �����뷴����
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(EmDcsAdpOper emOper, mt::TDCSOperReq *ptOper, mt::TDCSWbTabPageIdInfo *ptTabPageIdInfo);

/** ************************************************************
	* 
	* @brief    ����ת������ת
	*
	* @param	EmDcsAdpOper						rotateleft����rotateright
				TDCSOperReq     					��ͼ��������
	            TString								table id��
	* @return	u32
	* @note     ����ת������ת
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(EmDcsAdpOper emOper, mt::TDCSOperReq *ptOper, mt::TString *ptTabId);

/** ************************************************************
	* 
	* @brief    ����
	*
	* @param	EmDcsAdpOper						emWbClearScreen
				TDCSAdpOperReq     					��ͼ��������
	* @return	u32
	* @note     ����ת������ת
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(EmDcsAdpOper emOper, mt::TDCSOperReq *ptOper);


/** ************************************************************
	* 
	* @brief    ������Ļ��ץ�֣�����scrollscreen��Я������
	*
	* @param	TDCSOperReq     						������Ϣ
				TDCSScrollScreenInfo					������Ļ��Ϣ
	* @return	u32
	* @note     ������Ļ��ץ�֣�����scrollscreen��Я������
	*			
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSScrollScreenInfo *ptScrollScreenInfo);


/** ************************************************************
	* 
	* @brief    1. ȫ����ʾ��������
	*			   ��Ϊ���ʻ��������޴����Ի��ĳ���ԭ�л�����С��ʱ����һ��ȫ����ʾ���й��ܣ���С������ȫ����ʾ��������
	*			2. 100%������ʾ
	*			   �������ţ���Ҫһ���ο��㣻TL��������Ҫ�໥ת���ο���
	*
	* @param	EmDcsAdpOper     						������1��������2
	*			TDCSOperReq							��������
	*			TDCSWbDisPlayInfo						��ʾ����
	* @return	u32
	* @note     
	*			
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(EmDcsAdpOper emOper, TDCSAdpOperReq* ptOperReq, TDCSAdpWbDisPlayInfo* ptTDCSAdpDisPlayInfo);
u32 DCS_ADP_API OnDcsAdpWbOper(EmDcsAdpOper emOper, mt::TDCSOperReq *ptOper, mt::TDCSWbDisPlayInfo *ptDCSWbDisPlayInfo);


/** ************************************************************
	* 
	* @brief    �������
	*
	* @param	TDCSOperReq     						������Ϣ
				TDCSWbReginEraseOperInfo				���������Ϣ
	* @return	u32
	* @note     �������
	*			
	************************************************************* */
// u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbReginEraseOperInfo* ptReginEraseOperInfo);
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbReginEraseOperInfo *ptDCSWbReginEraseOperInfo);


/** ************************************************************
	* 
	* @brief    ����ͼƬ
	*
	* @param	TDCSOperReq     						������Ϣ
				TDCSWbInsertPicOperInfo				����ͼƬ��Ϣ
	* @return	u32
	* @note     ����ͼƬ
	*			
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbInsertPicOperInfo* ptInsertPicOperInfo);
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper, mt::TDCSWbInsertPicOperInfo *ptDCSWbInsertPicOperInfo);


/** ************************************************************
	* 
	* @brief    1. ѡ��ͼƬ����
	*			2. ѡ��ͼƬ��ת
	*			3. ѡ��ͼƬ�϶�
	*
	* @param	EmDcsAdpOper     						������1��������2������3
	*			TDCSOperReq							��������
	*			TDCSWbPitchPicOperInfo				����ѡ��ͼƬ
	* @return	u32
	* @note     
	*			
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(EmDcsAdpOper emOper, TDCSAdpOperReq* ptOperReq, TDCSAdpWbPitchPicOperInfo* ptPitchPicOperInfo);
u32 DCS_ADP_API OnDcsAdpWbOper(EmDcsAdpOper emOper, mt::TDCSOperReq *ptOper, mt::TDCSWbPitchPicOperInfo *ptDCSWbPitchPicOperInfo);


/** ************************************************************
	* 
	* @brief    ѡ��ͼƬɾ��
	*
	* @param	TDCSOperReq     						������Ϣ
				TDCSWbDelPicOperInfo					ѡ��ͼƬɾ��
	* @return	u32
	* @note     ѡ��ͼƬɾ��
	*			
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpWbOper(TDCSAdpOperReq* ptOperReq, TDCSAdpWbDelPicOperInfo* ptDelPicOperInfo);
u32 DCS_ADP_API OnDcsAdpWbOper(mt::TDCSOperReq *ptOper,  mt::TDCSWbDelPicOperInfo *ptDCSWbDelPicOperInfo);


/** ************************************************************
	* 
	* @brief    ������������л��װ�
	*
	* @param	TDCSAdpSwitchReq     					������Ϣ
	* @return	u32
	* @note     ������������л��װ�
	*			��Ӧ������Ϣ��Ev_DcsAdp_Switch_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpSwitchReq(TDCSAdpSwitchReq* ptSwitch);


/** ************************************************************
	* 
	* @brief    ���������ȡ��Ӧ�װ���Ϣ
	*
	* @param	s8 ����MT_STR_LEN_32  					����E164��
	            u32 									�װ�����
	* @return	u32
	* @note     ���������ȡ��Ӧ�װ���Ϣ
	*			��Ӧ������Ϣ��Ev_DcsAdp_GetCurWhiteBoard_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpGetWhiteBoardReq(s8* pachConfE164, s8* pachWbIndex);


/** ************************************************************
	* 
	* @brief    ���������ȡ��ǰ�װ���Ϣ
	*
	* @param	s8 ����MT_STR_LEN_32  					����E164��
	* @return	u32
	* @note     ���������ȡ��Ӧ�װ���Ϣ
	*			��Ӧ������Ϣ��Ev_DcsAdp_GetCurWhiteBoard_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpGetCurWhiteBoardReq(s8* pachConfE164);


/** ************************************************************
	* 
	* @brief    �������ɾ�����аװ���Ϣ
	*
	* @param	s8 ����MT_STR_LEN_32  					����E164��
	* @return	u32
	* @note     ���������ȡ��Ӧ�װ���Ϣ
	*			��Ӧ������Ϣ��Ev_DcsAdp_DelAllWhiteBoard_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpDelAllWhiteBoardReq(s8* pachConfE164);



/** ************************************************************
	* 
	* @brief    ���������ȡ���аװ���Ϣ
	*
	* @param	s8 ����MT_STR_LEN_32  					����E164��
	* @return	u32
	* @note     ���������ȡ���аװ���Ϣ
	*			��Ӧ������Ϣ��Ev_DcsAdp_GetAllWhiteBoard_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpGetAllWhiteBoardReq(s8* pachConfE164);


/** ************************************************************
	* 
	* @brief    �������ɾ����Ӧ�װ���Ϣ
	*
	* @param	s8 ����MT_STR_LEN_32  					����E164��
				u32 									�װ�����
	* @return	u32
	* @note     �������ɾ����Ӧ�װ���Ϣ
	*			��Ӧ������Ϣ��Ev_DcsAdp_DelWhiteBoard_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpDelWhiteBoardReq(s8* pachConfE164, s8* pachWbIndex);


/** ************************************************************
	* 
	* @brief    ������������װ���Ϣ
	*
	* @param	TDCSAdpNewWhiteBoard  					�°װ���Ϣ
	* @return	u32
	* @note     ������������װ���Ϣ
	*			��Ӧ������Ϣ��Ev_DcsAdp_NewWhiteBoard_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpNewWhiteBoardReq(TDCSAdpNewWhiteBoard* ptNewBoard);


/** ************************************************************
	* 
	* @brief    ������������û��б���Ϣ
	*
	* @param	s8 ����MT_STR_LEN_32  					����E164��
	* @return	u32
	* @note     ������������û��б���Ϣ
	*			��Ӧ������Ϣ��Ev_DcsAdp_GetUserList_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpGetUserListReq(s8* pachConfE164);


/** ************************************************************
	* 
	* @brief    �����������ȡ��Э��Ȩ
	*
	* @param	s8 ����MT_STR_LEN_32  					����E164��
	* @return	u32
	* @note     �����������ȡ��Э��Ȩ
	*			��Ӧ������Ϣ��Ev_DcsAdp_CancelOper_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpCancelOperReq(s8* pachConfE164);


/** ************************************************************
	* 
	* @brief    �����������Э��Ȩ
	*
	* @param	s8 ����MT_STR_LEN_32  					����E164��
	* @return	u32
	* @note     �����������Э��Ȩ
	*			��Ӧ������Ϣ��Ev_DcsAdp_ApplyOper_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpApplyOperReq(s8* pachConfE164);


/** ************************************************************
	* 
	* @brief    �������������᷽��ɫ
	*
	* @param	TDCSAdpSetUserRole  					��᷽��ɫ
	* @return	u32
	* @note     �������������᷽��ɫ
	*			��Ӧ������Ϣ��Ev_DcsAdp_SetUserRole_Rsp
	************************************************************* */
//u32 DCS_ADP_API OnDcsAdpSetUserRoleReq(TDCSAdpSetUserRole *ptUserInfo);


/** ************************************************************
	* 
	* @brief    �������������ֵ������Ϣ
	*
	* @param	TDCSAdpConfInfo  						������Ϣ
	* @return	u32
	* @note     �������������ֵ������Ϣ
	*			��Ӧ������Ϣ��Ev_DcsAdp_SetConfInfo_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpSetConfInfoReq(TDCSAdpConfInfo *ptConfInfo);


/** ************************************************************
	* 
	* @brief    �������ɾ����᷽
	*
	* @param	TDCSAdpMemberInfo  						��᷽��Ϣ
	* @return	u32
	* @note     �������ɾ����᷽
	*			��Ӧ������Ϣ��Ev_DcsAdp_DelMember_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpDelMemberReq(TDCSAdpMemberInfo *ptMemberInfo);


/** ************************************************************
	* 
	* @brief    ������������᷽
	*
	* @param	TDCSAdpMemberInfo  						��᷽��Ϣ
	* @return	u32
	* @note     ������������᷽
	*			��Ӧ������Ϣ��Ev_DcsAdp_AddMember_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpAddMemberReq(TDCSAdpMemberInfo *ptMemberInfo);


/** ************************************************************
	* 
	* @brief    ��������������
	*
	* @param	s8 ����MT_STR_LEN_32  					����E164��
	* @return	u32
	* @note     ��������������
	*			��Ӧ������Ϣ��Ev_DcsAdp_ReleaseConf_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpReleaseConfReq(s8* pachConfE164);


/** ************************************************************
	* 
	* @brief    �˻�����
	*
	* @param	s8 ����MT_STR_LEN_32  					����E164��
				u32				0: ͬʱ������Ƶ�����ݣ���Я��0����Ƶ����Ҳ�˳����װ����Ҳ�˳�->Ϊ�˽������������˳���Ƶ���飬�װ����������Ͳ��ٺ��и��ն���ᣬ��һ�ε�ʱ��
								1: ֻ��������Э������Я��1����Ƶ���黹�ڣ�ֻ���Ƴ��װ���飩
	* @return	u32
	* @note     �˻�����
	*			��Ӧ������Ϣ��Ev_DcsAdp_QuitConf_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpQuitConfReq(s8* pachConfE164, u32 dwForceFlag);


/** ************************************************************
	* 
	* @brief    �������
	*
	* @param	s8 ����MT_STR_LEN_32  					����E164��
	* @return	u32
	* @note     �������
	*			��Ӧ������Ϣ��Ev_DcsAdp_JoinConf_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpJoinConfReq(s8* pachConfE164);



/** ************************************************************
	* 
	* @brief    ��ǰ�ն˾ܾ����
	*
	* @param	TDCSAdpRejectJoinConf  					�ܾ����ṹ
	* @return	u32
	* @note     �������
	*			��Ӧ������Ϣ����
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpRejectJoinConfCmd(TDCSAdpRejectJoinConf *ptRejectJoinConf);


/** ************************************************************
	* 
	* @brief    �������ֻ�������
	*
	* @param	TDCSAdpCreateP2PConf  					�������ֻ���
	* @return	u32
	* @note     �������ֻ�������
	*			��Ӧ������Ϣ��Ev_DcsAdp_DcsCreateConf_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpCreateConfReq(TDCSAdpCreateConf *ptCreateConf);


/** ************************************************************
	* 
	* @brief    �ǳ����ֻ��������
	*
	* @param	����
	* @return	u32
	* @note     �ǳ����ֻ��������
	*			��Ӧ������Ϣ��Ev_DcsAdp_DcsLogout_Rsp
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpLogoutReq();


/** ************************************************************
	* 
	* @brief    ��¼���ֻ��������
	*
	* @param	TDCSAdpApsLoginParam 			��¼�ṹ
	* @return	u32
	* @note     ��¼���ֻ��������
	*			��Ӧ������Ϣ��Ev_DcsAdp_LoginSrv_Rsp
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpLoginSrvReq(EmDcsAdpType emType, TDCSAdpApsLoginParam* ptLoginParam);

/** ************************************************************
	* 
	* @brief    ���Э��������
	*
	* @param	TDCSAdpOperator 			Э������Ϣ
	* @return	u32
	* @note     ���Э��������
	*			��Ӧ������Ϣ��Ev_DcsAdp_AddOperator_Rsp
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpAddOperatorReq(TDCSAdpOperator* ptAdpAddOperReq);


/** ************************************************************
	* 
	* @brief    ɾ��Э��������
	*
	* @param	TDCSAdpOperator 			Э������Ϣ
	* @return	u32
	* @note     ɾ��Э��������
	*			��Ӧ������Ϣ��Ev_DcsAdp_DelOperator_Rsp
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpDelOperatorReq(TDCSAdpOperator* ptAdpAddOperReq);


/** ************************************************************
	* 
	* @brief    ��ѯ�����ַ
	*
	* @param	s8 			����E164	��
	* @return	u32
	* @note     ��ѯ�����ַ
	*			��Ӧ������Ϣ��Ev_DcsAdp_GetConfAddr_Rsp
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpGetConfAddrReq(s8* pachConfE164);


/** ************************************************************
	* 
	* @brief    ��ȡͼƬ���ص�ַ����
	*
	* @param	TDCSAdpImageUrl 			����
	* @return	u32
	* @note     ��ȡͼƬ���ص�ַ����
	*			��Ӧ������Ϣ��Ev_DcsAdp_DownloadImage_Rsp
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpDownloadImageReq(TDCSAdpImageUrl* ptImageUrl);


/** ************************************************************
	* 
	* @brief    ��ȡͼƬ�ϴ���ַ����
	*
	* @param	TDCSAdpImageUrl 			����
	* @return	u32
	* @note     ��ȡͼƬ�ϴ���ַ����
	*			��Ӧ������Ϣ��Ev_DcsAdp_UploadImage_Rsp
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpUploadImageReq(TDCSAdpImageUrl* ptImageUrl);



/** ************************************************************
	* 
	* @brief    �ܾ�����Э����
	*
	* @param	TDCSAdpOperator 			����
	* @return	u32
	* @note     �ܾ�����Э����
	*			��Ӧ������Ϣ����
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpRejectOperatorCmd(TDCSAdpOperator* ptOperator);


/** ************************************************************
	* 
	* @brief    �ϴ��ļ�
	*
	* @param	pchUploadUrl 			�ϴ�URL
    * @param	pchFilePathName 		�ļ���Ϣ
	* @return	u32
	* @note     �ϴ��ļ�
	*			��Ӧ������Ϣ��Ev_DcsAdp_UploadFile_Ntf
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpUploadFileCmd(const s8* pchUploadUrl, TDCSAdpFileInfo& tFileInfo/*const s8* pchFilePathName*/);

/** ************************************************************
	* 
	* @brief    �����ļ�
	*
	* @param	pchDownloadUrl 		�ļ�URL
    * @param	pchFilePathName 		�ļ���Ϣ
	* @return	u32
	* @note     �����ļ�
	*			��Ӧ������Ϣ��Ev_DcsAdp_DownloadFile_Ntf
	*
	************************************************************* */
u32 DCS_ADP_API OnDcsAdpDownloadFileReq(const s8* pchDownloadUrl, TDCSAdpFileInfo& tFileInfo/*const s8* pchFilePathName*/);
#endif
















