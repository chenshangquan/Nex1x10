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

#ifndef _MTUTILS_H_
#define _MTUTILS_H_

#include "errcode/mterrcode_mtutils.h"

#include "utils/mtutilsblockmanager.h"		/* �߳�������ѯ�ӿ� */

#include "utils/mtutilscharset.h"			/* �ַ������໥ת���ӿ� */

#include "utils/mtutilsencrypt.h"			/* �ַ���/�ļ����ܽ��ܡ�У�鹫�ú��� */

#include "utils/mtutilsexception.h"			/* �쳣���� */

#include "utils/mtutilsipstring.h"			/* ip��ַ��ؽӿ� */

#include "utils/mtutilssystem.h"			/* ϵͳ��ؽӿ� */

#include "utils/mtutilscommon.h"			/* һ�㹫�ú����ӿ� */

#include "utils/sharedmemoryblock.h"		/* �����ڴ� */

#include "utils/mtutilsmedia.h"		/* ý�� */



/** ***********************************************************
* 
* @brief    �ڲ���ӡ����
*
* @param	[in] pchFmt ��ʽ�����ַ���
*
* @return	��
*           
**************************************************************/
void mtUtilsLog(const s8 *pchFmt, ...);

/**----------------------------------------------------------------------
* MtUtilsInit
* 
* @brief   ����ģ���ʼ������
* 
* @param	[in] pfPrintFunc ��ӡ��������ָ��
* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
* @see
------------------------------------------------------------------------*/
MTCBB_API BOOL32 MtUtilsInit( MTUTILS::PRINTFUNC pfPrintFunc );

#endif