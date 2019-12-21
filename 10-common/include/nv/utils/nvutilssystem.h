/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   ϵͳ��ع��ú����ӿ�
 * @author  �Ĵ���
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/
#ifndef _NVUTILSSYSTEM_H_
#define _NVUTILSSYSTEM_H_
#include "nvutilstype.h"
#include "kdvtype.h"
#include "nvmacro.h"
#include "nvconst.h"
#include <vector>

 /////// bitset �ﶨ����std:min, std:max, �������Զ����min, max ��ͻ
#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max
#include <bitset>
#pragma pop_macro("min")
#pragma pop_macro("max")

/******************************************************************************
* @namespace    NVUTILS
******************************************************************************/
namespace NVUTILS {

/*!**********************************************************
* @fn      EmOSType nvGetOsType()
* @brief   ��ȡ����ϵͳ����
* @return  ����ϵͳ����
*************************************************************/
NVCBB_API EmNvOSType nvGetOsType();

/*!**********************************************************
* @fn      u32 nvGetCurrentThreadID ()
* @brief   ��ȡ��ǰ�̱߳�ʶ��
* @return  �߳�ID
*************************************************************/
NVCBB_API u32 nvGetCurrentThreadID();

/*!**********************************************************
* @fn      u32 nvGetPID ()
* @brief   ��ȡ��ǰ���̱�ʶ��
* @return  ����ID
*************************************************************/
NVCBB_API u32 nvGetPID();

/*!**********************************************************
* @fn      BOOL32 nvIsLittleEndian()
* @brief   ��ȡCPU�ֽ���
* @return  TRUE:С��ģʽ  FALSE:���ģʽ
*************************************************************/
NVCBB_API BOOL32 nvIsLittleEndian();

/*!**********************************************************
* @fn      u32 nvGetSysRunTime()
* @brief   Linux��ȡϵͳ������ʱ��
* @return  ϵͳ��������ʱ�䣨��λ:�룩
*************************************************************/
NVCBB_API u32 nvGetSysRunTime();

/*!**********************************************************
* @fn      u32 nvGetSysIdleTime()
* @brief   Linux��ȡϵͳ����ʱ��
* @return  ϵͳ����ʱ�䣨��λ:�룩
*************************************************************/
NVCBB_API u32 nvGetSysIdleTime();

/*!**********************************************************
* @fn      u32 nvGetTickCount()
* @brief   �Ӳ���ϵͳ�����������������ĺ�����
* @return  ʱ�䣨��λ:���룩
*************************************************************/
NVCBB_API u32 nvGetTickCount();

/*!**********************************************************
* @fn      u32 nvGetCurTime()
* @brief   ��ȡ��ǰϵͳʱ��,��ȷ������
* @param   [out] tTime  ��ǰϵͳʱ��
* @return  ��
*************************************************************/
NVCBB_API void nvGetCurTime(TDateTime &tDateTime);

/*!**********************************************************
* @fn      u32 nvGetCurWorkDir(s8 *pchPath, u32 dwLen)
* @brief   ��ȡ����ǰ����·��
* @param   [out] pchPath  ��ǰ����·��
* @param   [in]  dwLen    ����������
* @return  NV_SUCCESS:�ɹ� 
           ERR_NVCBB_BUF_OVERFLOW: buf̫С
*************************************************************/
NVCBB_API u32 nvGetCurrentWorkDir(s8 *pchPath, u32 dwLen);

/*!**********************************************************
* @fn      u32 nvCreateFile(const s8 *pchPath)
* @brief   �½��ļ�
* @param   [in] pchPath  �ļ�·��, utf8����
* @return  NV_SUCCESS:�ɹ� 
		   ERR_NVCBB_PATH_EXIST:   ʧ�� �ļ��Ѵ���
		   ERR_NVCBB_INVALID_PATH: ʧ�� �Ƿ�·��
*************************************************************/
NVCBB_API u32 nvCreateFile(const s8 *pchPath);

/*!**********************************************************
* @fn      u32 nvMakeDir(const s8 *pchPath)
* @brief   �½��ļ���
* @param   [in] pchPath  �ļ���·��, utf8����
* @return  NV_SUCCESS:�ɹ� 
		   ERR_NVCBB_INVALID_PATH: ʧ��
*************************************************************/
NVCBB_API u32 nvMakeDir(const s8 *pchPath);

/*!**********************************************************
* @fn      u32 nvMakeDir(const s8 *pchPath)
* @brief   �����㼶�ļ���  �� /usr/dir1/dir2/dir3
* @param   [in] pchPath  �ļ���·��, utf8����
* @return  NV_SUCCESS: �ɹ� 
           ERR_NVCBB_INVALID_PATH: ʧ��
*************************************************************/
NVCBB_API u32 nvMakeHierarchyDir(const s8 *pchPath);

/*!**********************************************************
* @fn      u32 nvIsPathExist(const s8 *pchPath)
* @brief   �ж�·���Ƿ����
* @param   [in] pchPath, utf8����
* @return  TRUE: ���� 
           FALSE: ������
*************************************************************/
NVCBB_API BOOL32 nvIsPathExist(const s8 *pchPath);

/*!**********************************************************
* @fn      u32 nvIsFileExist(const s8 *pchFilename)
* @brief   �ж��ļ��Ƿ����
* @param   [in] pchFilename �ļ���, utf8����
* @return  TRUE: ���� 
           FALSE: ������
*************************************************************/
NVCBB_API BOOL32 nvIsFileExist(const s8 *pchFilename);

/*!**********************************************************
* @fn      u32 nvRenameFile(const s8 *pchOldPath, const s8 *pchNewPath)
* @brief   �������ļ�(·��)
* @param   [in] pchOldPath ��ǰ����, utf8����
* @param   [in] pchNewPath �޸ĺ������, utf8����
* @return  NV_SUCCESS: �ɹ� 
           NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvRenameFile(const s8 *pchOldPath, const s8 *pchNewPath);

/*!**********************************************************
* @fn      u32 nvAttribFile(const s8 *pchFileName, BOOL32 bReadOnly)
* @brief   �޸��ļ���д����
* @param   [in] pchFileName �ļ���, utf8����
* @param   [in] bReadOnly   ֻ�� / �ɶ�д
* @return  NV_SUCCESS:�ɹ� 
           NV_FAILED:ʧ��
*************************************************************/
NVCBB_API u32 nvAttribFile(const s8 *pchFileName, BOOL32 bReadOnly);

/*!**********************************************************
* 
* @brief   ��ȡ�ļ���С
* @param   [in] pchFileName �ļ���, utf8����
* @param   [out] dwSize     �ļ���С
*
* @return  NV_SUCCESS:�ɹ� 
           NV_FAILED:ʧ��
*************************************************************/
NVCBB_API u32 nvGetFileSize(const s8 *pchFileName, u32 &dwSize);


/*!**********************************************************
*
* @brief   ��������
* @param   [in]  pchAppPath      ����·����, utf8����
* @param   [in]  pchCmdLine      �����в���
* @param   [out] dwProcessId     �����Ľ��̵Ľ���ID
* @param   [out] pProcessHandle  (WIN32)�����Ľ��̵ľ��
*
* @return  NV_SUCCESS:�ɹ� 
           NV_FAILED:ʧ��
*************************************************************/
NVCBB_API u32 nvCreateProcess(const s8 *pchAppPath, const s8 *pchCmdLine, u32 &dwProcessId, void *pProcessHandle = NULL);

/*!**********************************************************
*
* @brief   ҵ��������˿ں������������õ� ���ô˽ӿڰ󶨶˿�
*          ��ֹ��ռ���õ�ʱ�ٽ��
* @param   [in]  wPort �˿�
*
* @return  NV_SUCCESS:�ɹ� 
           NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvBindUdpPort(u16 wPort);

/*!**********************************************************
*
* @brief   �����nvBindUdpPort�󶨵Ķ˿�
*          
* @param   [in]  wPort �˿�
*
* @return  NV_SUCCESS:�ɹ� 
           NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvUnBindUdpPort(u16 wPort);

/*!**********************************************************
*
* @brief   ɾ���ļ�
*          
* @param   [in]  pchFilePath �ļ�·��, utf8����
*
* @return  NV_SUCCESS:�ɹ� 
           NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvRemoveFile(const s8 *pchFilePath);

/*!**********************************************************
*
* @brief   �ж�tcp�˿��Ƿ�ʹ��
*          
* @param   [in]  wTcpPort �˿ں�
*
* @return  TRUE:��ʹ�� 
           FALSE: δʹ��
*************************************************************/
NVCBB_API BOOL32 nvIsTcpPortUsed(u16 wTcpPort);

/*!**********************************************************
*
* @brief   �ж�udp�˿��Ƿ�ʹ��
*          
* @param   [in]  wUdpPort �˿ں�
*
* @return  TRUE:��ʹ�� 
           FALSE: δʹ��
*************************************************************/
NVCBB_API BOOL32 nvIsUdpPortUsed(u16 wUdpPort);

/*!**********************************************************
*
* @brief   ��ȡ���һ�δ�����
*          
* @param   
*
* @return   ������
*************************************************************/
NVCBB_API u32 nvGetLastError();

//��ȡwindows�ġ��˿ڼ���
NVCBB_API void nvGetWindowsTcpPortBitset(std::bitset<MAX_PORT_VALUE> &bstTcpState);

NVCBB_API BOOL32 nvGetLinuxTcpPortBitset(std::bitset<MAX_PORT_VALUE> &bstTcpState);


//��ȡwindows�ġ��˿ڼ���
NVCBB_API void nvGetWindowsUdpPortBitset(std::bitset<MAX_PORT_VALUE> &bstUdpState);

NVCBB_API BOOL32 nvGetLinuxUdpPortBitset(std::bitset<MAX_PORT_VALUE> &bstUdpState);




}


#endif // _NVUTILSSYSTEM_H_