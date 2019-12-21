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

#ifndef _NVEXCEPTION_H_
#define _NVEXCEPTION_H_


#include "kdvtype.h"
#include "nvutilstype.h"
#include "nvmacro.h"


/******************************************************************************
* @namespace    NVUTILS
******************************************************************************/
namespace NVUTILS {


/*!**********************************************************
* @fn      u32 nvInstallExceptionCatch(const s8 *pchModuleName, const s8 *pchLogPath)
* @brief   Linuxϵͳ��Ϊ��ִ��ģ�鰲װ�쳣����
* @param   [in] pchModuleName:��ִ��ģ����
* @param   [in] pchLogName:    �쳣��־�ļ���
* @return  NV_SUCCESS:        �ɹ� 
           NV_FAILED:         ʧ��
*************************************************************/
NVCBB_API u32 nvInstallExceptionCatch(const s8 *pchModuleName, const s8 *pchLogName);


}




#endif //_NVEXCEPTION_H_