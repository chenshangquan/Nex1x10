#ifndef _NVDSC_H_
#define _NVDSC_H_
#include <string>
#include "kdvtype.h"
#include "nvdscommon.h"
#include "nvmacro.h"
#include <stdio.h>

#define IMIX_MAX_DEVICEVER_LEN 38

/**----------------------------------------------------------------------
* nvDscSet
* 
* @brief   д��һ�����ݵ����ݹ��������
* 
* @param   [in] strKey ���ݵ�key
* @param   [in] pData  һ��buf��������д�������
* @param   [in] dwSize ��д������ݴ�С
* @return  BOOL32 DSE_OK:�ɹ����� DSE_ERROR:д��ʧ��
------------------------------------------------------------------------*/
NVCBB_API u32 nvDscSet(KEY strKey, void *pData, u32 dwSize);

/**----------------------------------------------------------------------
* nvDscGet
* 
* @brief   �����ݹ����������ȡһ������
* 
* @param   [in] strKey ���ݵ�key
* @param   [inout] pData  һ��buf�����ڽ�������
* @param   [inout] dwSize ����ʱΪpData��Ӧbuf�Ĵ�С������ʱΪ�õ����ݵ�ʵ�ʴ�С
* @return  BOOL32 DSE_OK:�ɹ����� DSE_BUF:�����buf̫С����ʱdwSize�᷵��ʵ����Ҫ�Ĵ�С DSE_ERROR:����ʧ�����
------------------------------------------------------------------------*/
NVCBB_API u32 nvDscGet(KEY strKey, void *pData, u32 &dwSize);

/**----------------------------------------------------------------------
* nvGetBuildVersion
* 
* @brief   ��ȡimix����������Ϣ
* 
* @return  s8 BuildVersion:����������Ϣ
------------------------------------------------------------------------*/
NVCBB_API s8* nvGetBuildVersion();

#endif // _NVDSC_H_