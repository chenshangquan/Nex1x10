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



#ifndef _NVUPGRADE_H_
#define _NVUPGRADE_H_

#include "nvmsg.h"
#include "nvstruct.pb.h"
#include "nvstruct.h"

namespace NVUPGRADE {

///< ����������ϲ�Ļص�����, cMsgΪ�ѷ�װ�õ���Ϣ��sdk�����׸��ϲ�
typedef void (*pfCbSysUpgrageCallback)(nvmsg::CNvMsg &cMsg);

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
void nvCheckUpdate(nv::TNVUpgradeClientInfo &tInfo, pfCbSysUpgrageCallback pfFunc, BOOL32 bGetRecommend = TRUE);



/** ************************************************************
* 
* @brief    ȡ��������
*
* @param	��
* @return	��
* @note     
*
************************************************************* */
void nvCancelCheckUpdate();


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
void nvStartDownloadUpgradeFile(const s8 *pchFilePath, u32 dwVerId = 0);


/** ************************************************************
* 
* @brief    ȡ�����ظ����ļ�
*
* @param	��
* @return	��
* @note     
*
************************************************************* */
void nvCancelDownloadUpgradeFile();


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


/** ************************************************************
* 
* @brief    ��ʼ����(Ӳ�ն�)
*
* @param	��
* @return	��
* @note     
*
************************************************************* */
void nvStartUpgrade();


};



/**---------------------------------------------------------------------- 
* 
* @brief    ����������ϵͳ
* 
* @param	��
* @return   TRUE:  �ɹ�
*           FALSE��ʧ��
------------------------------------------------------------------------*/
extern "C" NVCBB_API BOOL32 UpgradeStart(TMdlStartParam &tMdlStartparam);



/**---------------------------------------------------------------------- 
* 
* @brief    ֹͣ������ϵͳ
* 
* @param	��
* @return   TRUE:  �ɹ�
*           FALSE��ʧ��
------------------------------------------------------------------------*/
extern "C" NVCBB_API BOOL32 UpgradeStop();


#endif  //_NVUPGRADE_H_