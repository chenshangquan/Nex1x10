/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   ϵͳ����ģ��ͷ�ļ�
 * @author  �Ĵ���
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/



#ifndef _MTUPGRADE_H_
#define _MTUPGRADE_H_

#include "mtmsg.h"
#include "struct.pb.h"
#include "mtstruct.h"

namespace MTUPGRADE {

///< ����������ϲ�Ļص�����, cMsgΪ�ѷ�װ�õ���Ϣ��sdk�����׸��ϲ�
typedef void (*pfCbSysUpgrageCallback)(mtmsg::CMtMsg &cMsg);

/** ************************************************************
* 
* @brief    �����½ӿ�
*
* @param	[in] tInfo    �����������ն���Ϣ
* @param	[in] pfFunc   �ϲ��ṩ�Ļص��ӿ� ������������������Ϣ
* @param	[in] bGetRecommend    �Ƿ��ȡ�Ƽ��汾 (TRUE:��ȡ�Ƽ��汾  FALSE:��ȡ�汾�б�)
* @return	��
* @note     
*
************************************************************* */
void mtCheckUpdate(mt::TMTUpgradeClientInfo &tInfo, pfCbSysUpgrageCallback pfFunc, BOOL32 bGetRecommend = TRUE);



/** ************************************************************
* 
* @brief    ȡ��������
*
* @param	��
* @return	��
* @note     
*
************************************************************* */
void mtCancelCheckUpdate();


/** ************************************************************
* 
* @brief    ��ʼ���ظ����ļ���ָ��Ŀ¼
*
* @param	[in] pchFilePath �ļ����ش��·��
* @param	[in] dwVerId     ������õ��İ汾�б��ж��ʱ,ָ��Ҫ���صİ汾
* @return	��
* @note     
*
************************************************************* */
void mtStartDownloadUpgradeFile(const s8 *pchFilePath, u32 dwVerId = 0);


/** ************************************************************
* 
* @brief    ȡ�����ظ����ļ�
*
* @param	��
* @return	��
* @note     
*
************************************************************* */
void mtCancelDownloadUpgradeFile();


/** ************************************************************
* 
* @brief    ����״̬֪ͨ
*
* @param	��
* @return	��
* @note     �����ļ������ز����������㲥���  ���������㲥��������ʾ
*
************************************************************* */
void SetDownloadState(BOOL32 bPause);

void ResumeUpgrade( mt::TS32 nReason );


/** ************************************************************
* 
* @brief    ��ʼ����(Ӳ�ն�)
*
* @param	��
* @return	��
* @note     
*
************************************************************* */
void mtStartUpgrade();


};



/**---------------------------------------------------------------------- 
* 
* @brief    ����������ϵͳ
* 
* @param	��
* @return   TRUE:  �ɹ�
*           FALSE��ʧ��
------------------------------------------------------------------------*/
extern "C" MTCBB_API BOOL32 UpgradeStart(TMdlStartParam &tMdlStartparam);



/**---------------------------------------------------------------------- 
* 
* @brief    ֹͣ������ϵͳ
* 
* @param	��
* @return   TRUE:  �ɹ�
*           FALSE��ʧ��
------------------------------------------------------------------------*/
extern "C" MTCBB_API BOOL32 UpgradeStop();


#endif  //_MTUPGRADE_H_