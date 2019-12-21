/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   �쳣�����ú���
 * @author  �Ĵ���
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/

#ifndef _MTEXCEPTION_H_
#define _MTEXCEPTION_H_


#include "kdvtype.h"
#include "mtutilstype.h"
#include "mtmacro.h"


/******************************************************************************
* @namespace    MTUTILS
******************************************************************************/
namespace MTUTILS {


/*!**********************************************************
* @fn      u32 mtInstallExceptionCatch(const s8 *pchModuleName, const s8 *pchLogPath)
* @brief   Linuxϵͳ��Ϊ��ִ��ģ�鰲װ�쳣����
* @param   [in] pchModuleName:��ִ��ģ����
* @param   [in] pchLogName:    �쳣��־�ļ���
* @return  MT_SUCCESS:        �ɹ� 
           MT_FAILED:         ʧ��
*************************************************************/
MTCBB_API u32 mtInstallExceptionCatch(const s8 *pchModuleName, const s8 *pchLogName);


}




#endif //_MTEXCEPTION_H_