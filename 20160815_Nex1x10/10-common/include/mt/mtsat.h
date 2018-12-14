/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   ����ģ�鹫��ͷ�ļ�
 * @author  �Ĵ���
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/

#ifndef MT_SAT_H_ 
#define MT_SAT_H_

#include "kdvtype.h"
#include "mtstruct.h"
#include "mtmacro.h"


/**---------------------------------------------------------------------- 
* 
* @brief    ��������ģ��
* 
* @param	��
* @return   TRUE:  �ɹ�
*           FALSE��ʧ��
------------------------------------------------------------------------*/
extern "C" MTCBB_API BOOL32 MtSatStart(TMdlStartParam &tMdlStartParam);


/**---------------------------------------------------------------------- 
* 
* @brief    ֹͣ����ģ��
* 
* @param	��
* @return   TRUE:  �ɹ�
*           FALSE��ʧ��
------------------------------------------------------------------------*/
extern "C" MTCBB_API BOOL32 MtSatStop();


/**---------------------------------------------------------------------- 
* 
* @brief    �ṩ��ϵͳ���Ƶ���
* 
* @param	��
* @return   ��
------------------------------------------------------------------------*/
extern "C" MTCBB_API void MtSatAddStaticLib();


#endif //MT_SAT_H_