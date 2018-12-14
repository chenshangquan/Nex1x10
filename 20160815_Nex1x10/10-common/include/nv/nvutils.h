/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   ���ú���
 * @author  �Ĵ���
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/

#ifndef _NVUTILS_H_
#define _NVUTILS_H_

#include "errcode/nverrcode_nvutils.h"

#include "utils/nvutilsblockmanager.h"		/* �߳�������ѯ�ӿ� */

#include "utils/nvutilscharset.h"			/* �ַ������໥ת���ӿ� */

#include "utils/nvutilsencrypt.h"			/* �ַ���/�ļ����ܽ��ܡ�У�鹫�ú��� */

#include "utils/nvutilsexception.h"			/* �쳣���� */

#include "utils/nvutilsipstring.h"			/* ip��ַ��ؽӿ� */

#include "utils/nvutilssystem.h"			/* ϵͳ��ؽӿ� */

#include "utils/nvutilscommon.h"			/* һ�㹫�ú����ӿ� */

#include "utils/sharedmemoryblock.h"		/* �����ڴ� */

#include "utils/nvutilsmedia.h"		/* ý�� */



/** ***********************************************************
* 
* @brief    �ڲ���ӡ����
*
* @param	[in] pchFnv ��ʽ�����ַ���
*
* @return	��
*           
**************************************************************/
void nvUtilsLog(const s8 *pchFnv, ...);

/**----------------------------------------------------------------------
* NvUtilsInit
* 
* @brief   ����ģ���ʼ������
* 
* @param	[in] pfPrintFunc ��ӡ��������ָ��
* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
* @see
------------------------------------------------------------------------*/
NVCBB_API BOOL32 NvUtilsInit( NVUTILS::PRINTFUNC pfPrintFunc );

#endif