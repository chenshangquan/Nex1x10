/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   Сҵ����ϵͳ����ͷ�ļ�
 * @author  �Ĵ���
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/


#ifndef _MT_MISC_H_
#define _MT_MISC_H_


#include "kdvtype.h"
#include "mtstruct.h"
#include "mtmacro.h"

/**---------------------------------------------------------------------- 
* 
* @brief    ����Сҵ����ϵͳ
* 
* @param	��
* @return   TRUE:  �ɹ�
*           FALSE��ʧ��
------------------------------------------------------------------------*/
extern "C" MTCBB_API BOOL32 MiscStart(TMdlStartParam &tMdlStartparam);



/**---------------------------------------------------------------------- 
* 
* @brief    ֹͣСҵ����ϵͳ
* 
* @param	��
* @return   TRUE:  �ɹ�
*           FALSE��ʧ��
------------------------------------------------------------------------*/
extern "C" MTCBB_API BOOL32 MiscStop();


#endif //_MT_MISC_H_