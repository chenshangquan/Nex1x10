#ifndef _MTDSC_H_
#define _MTDSC_H_
#include <string>
#include "kdvtype.h"
#include "mtdscommon.h"
#include "mtmacro.h"

/**----------------------------------------------------------------------
* mtDscSet
* 
* @brief   д��һ�����ݵ����ݹ��������
* 
* @param   [in] strKey ���ݵ�key
* @param   [in] pData  һ��buf��������д�������
* @param   [in] dwSize ��д������ݴ�С
* @return  BOOL32 DSE_OK:�ɹ����� DSE_ERROR:д��ʧ��
------------------------------------------------------------------------*/
MTCBB_API u32 mtDscSet(KEY strKey, void *pData, u32 dwSize);

/**----------------------------------------------------------------------
* mtDscGet
* 
* @brief   �����ݹ����������ȡһ������
* 
* @param   [in] strKey ���ݵ�key
* @param   [inout] pData  һ��buf�����ڽ�������
* @param   [inout] dwSize ����ʱΪpData��Ӧbuf�Ĵ�С������ʱΪ�õ����ݵ�ʵ�ʴ�С
* @return  BOOL32 DSE_OK:�ɹ����� DSE_BUF:�����buf̫С����ʱdwSize�᷵��ʵ����Ҫ�Ĵ�С DSE_ERROR:����ʧ�����
------------------------------------------------------------------------*/
MTCBB_API u32 mtDscGet(KEY strKey, void *pData, u32 &dwSize);

#endif // _MTDSC_H_