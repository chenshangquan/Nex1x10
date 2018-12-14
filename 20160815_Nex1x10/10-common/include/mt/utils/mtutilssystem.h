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
#ifndef _MTUTILSSYSTEM_H_
#define _MTUTILSSYSTEM_H_
#include "mtutilstype.h"
#include "kdvtype.h"
#include "mtmacro.h"
#include "mtconst.h"
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
* @namespace    MTUTILS
******************************************************************************/
namespace MTUTILS {

/*!**********************************************************
* @fn      EmOSType mtGetOsType()
* @brief   ��ȡ����ϵͳ����
* @return  ����ϵͳ����
*************************************************************/
MTCBB_API EmMtOSType mtGetOsType();

/*!**********************************************************
* @fn      u32 mtGetCurrentThreadID ()
* @brief   ��ȡ��ǰ�̱߳�ʶ��
* @return  �߳�ID
*************************************************************/
MTCBB_API u32 mtGetCurrentThreadID();

/*!**********************************************************
* @fn      u32 mtGetPID ()
* @brief   ��ȡ��ǰ���̱�ʶ��
* @return  ����ID
*************************************************************/
MTCBB_API u32 mtGetPID();

/*!**********************************************************
* @fn      BOOL32 mtIsLittleEndian()
* @brief   ��ȡCPU�ֽ���
* @return  TRUE:С��ģʽ  FALSE:���ģʽ
*************************************************************/
MTCBB_API BOOL32 mtIsLittleEndian();

/*!**********************************************************
* @fn      u32 mtGetSysRunTime()
* @brief   Linux��ȡϵͳ������ʱ��
* @return  ϵͳ��������ʱ�䣨��λ:�룩
*************************************************************/
MTCBB_API u32 mtGetSysRunTime();

/*!**********************************************************
* @fn      u32 mtGetSysIdleTime()
* @brief   Linux��ȡϵͳ����ʱ��
* @return  ϵͳ����ʱ�䣨��λ:�룩
*************************************************************/
MTCBB_API u32 mtGetSysIdleTime();

/*!**********************************************************
* @fn      u32 mtGetTickCount()
* @brief   �Ӳ���ϵͳ�����������������ĺ�����
* @return  ʱ�䣨��λ:���룩
*************************************************************/
MTCBB_API u32 mtGetTickCount();

/*!**********************************************************
* @fn      u32 mtGetCurTime()
* @brief   ��ȡ��ǰϵͳʱ��,��ȷ������
* @param   [out] tTime  ��ǰϵͳʱ��
* @return  ��
*************************************************************/
MTCBB_API void mtGetCurTime(TDateTime &tDateTime);

/*!**********************************************************
* @fn      u32 mtGetCurWorkDir(s8 *pchPath, u32 dwLen)
* @brief   ��ȡ����ǰ����·��
* @param   [out] pchPath  ��ǰ����·��
* @param   [in]  dwLen    ����������
* @return  MT_SUCCESS:�ɹ� 
           ERR_MTCBB_BUF_OVERFLOW: buf̫С
*************************************************************/
MTCBB_API u32 mtGetCurrentWorkDir(s8 *pchPath, u32 dwLen);

/*!**********************************************************
* @fn      u32 mtCreateFile(const s8 *pchPath)
* @brief   �½��ļ�
* @param   [in] pchPath  �ļ�·��, utf8����
* @return  MT_SUCCESS:�ɹ� 
		   ERR_MTCBB_PATH_EXIST:   ʧ�� �ļ��Ѵ���
		   ERR_MTCBB_INVALID_PATH: ʧ�� �Ƿ�·��
*************************************************************/
MTCBB_API u32 mtCreateFile(const s8 *pchPath);

/*!**********************************************************
* @fn      u32 mtMakeDir(const s8 *pchPath)
* @brief   �½��ļ���
* @param   [in] pchPath  �ļ���·��, utf8����
* @return  MT_SUCCESS:�ɹ� 
		   ERR_MTCBB_INVALID_PATH: ʧ��
*************************************************************/
MTCBB_API u32 mtMakeDir(const s8 *pchPath);

/*!**********************************************************
* @fn      u32 mtMakeDir(const s8 *pchPath)
* @brief   �����㼶�ļ���  �� /usr/dir1/dir2/dir3
* @param   [in] pchPath  �ļ���·��, utf8����
* @return  MT_SUCCESS: �ɹ� 
           ERR_MTCBB_INVALID_PATH: ʧ��
*************************************************************/
MTCBB_API u32 mtMakeHierarchyDir(const s8 *pchPath);

/*!**********************************************************
* @fn      u32 mtIsPathExist(const s8 *pchPath)
* @brief   �ж�·���Ƿ����
* @param   [in] pchPath, utf8����
* @return  TRUE: ���� 
           FALSE: ������
*************************************************************/
MTCBB_API BOOL32 mtIsPathExist(const s8 *pchPath);

/*!**********************************************************
* @fn      u32 mtIsFileExist(const s8 *pchFilename)
* @brief   �ж��ļ��Ƿ����
* @param   [in] pchFilename �ļ���, utf8����
* @return  TRUE: ���� 
           FALSE: ������
*************************************************************/
MTCBB_API BOOL32 mtIsFileExist(const s8 *pchFilename);

/*!**********************************************************
* @fn      u32 mtRenameFile(const s8 *pchOldPath, const s8 *pchNewPath)
* @brief   �������ļ�(·��)
* @param   [in] pchOldPath ��ǰ����, utf8����
* @param   [in] pchNewPath �޸ĺ������, utf8����
* @return  MT_SUCCESS: �ɹ� 
           MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtRenameFile(const s8 *pchOldPath, const s8 *pchNewPath);

/*!**********************************************************
* @fn      u32 mtAttribFile(const s8 *pchFileName, BOOL32 bReadOnly)
* @brief   �޸��ļ���д����
* @param   [in] pchFileName �ļ���, utf8����
* @param   [in] bReadOnly   ֻ�� / �ɶ�д
* @return  MT_SUCCESS:�ɹ� 
           MT_FAILED:ʧ��
*************************************************************/
MTCBB_API u32 mtAttribFile(const s8 *pchFileName, BOOL32 bReadOnly);

/*!**********************************************************
* 
* @brief   ��ȡ�ļ���С
* @param   [in] pchFileName �ļ���, utf8����
* @param   [out] dwSize     �ļ���С
*
* @return  MT_SUCCESS:�ɹ� 
           MT_FAILED:ʧ��
*************************************************************/
MTCBB_API u32 mtGetFileSize(const s8 *pchFileName, u32 &dwSize);


/*!**********************************************************
*
* @brief   ��������
* @param   [in]  pchAppPath      ����·����, utf8����
* @param   [in]  pchCmdLine      �����в���
* @param   [out] dwProcessId     �����Ľ��̵Ľ���ID
* @param   [out] pProcessHandle  (WIN32)�����Ľ��̵ľ��
*
* @return  MT_SUCCESS:�ɹ� 
           MT_FAILED:ʧ��
*************************************************************/
MTCBB_API u32 mtCreateProcess(const s8 *pchAppPath, const s8 *pchCmdLine, u32 &dwProcessId, void *pProcessHandle = NULL);

/*!**********************************************************
*
* @brief   ҵ��������˿ں������������õ� ���ô˽ӿڰ󶨶˿�
*          ��ֹ��ռ���õ�ʱ�ٽ��
* @param   [in]  wPort �˿�
*
* @return  MT_SUCCESS:�ɹ� 
           MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtBindUdpPort(u16 wPort);

/*!**********************************************************
*
* @brief   �����mtBindUdpPort�󶨵Ķ˿�
*          
* @param   [in]  wPort �˿�
*
* @return  MT_SUCCESS:�ɹ� 
           MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtUnBindUdpPort(u16 wPort);

/*!**********************************************************
*
* @brief   ɾ���ļ�
*          
* @param   [in]  pchFilePath �ļ�·��, utf8����
*
* @return  MT_SUCCESS:�ɹ� 
           MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtRemoveFile(const s8 *pchFilePath);

/*!**********************************************************
*
* @brief   �ж�tcp�˿��Ƿ�ʹ��
*          
* @param   [in]  wTcpPort �˿ں�
*
* @return  TRUE:��ʹ�� 
           FALSE: δʹ��
*************************************************************/
MTCBB_API BOOL32 mtIsTcpPortUsed(u16 wTcpPort);

/*!**********************************************************
*
* @brief   �ж�udp�˿��Ƿ�ʹ��
*          
* @param   [in]  wUdpPort �˿ں�
*
* @return  TRUE:��ʹ�� 
           FALSE: δʹ��
*************************************************************/
MTCBB_API BOOL32 mtIsUdpPortUsed(u16 wUdpPort);

/*!**********************************************************
*
* @brief   ��ȡ���һ�δ�����
*          
* @param   
*
* @return   ������
*************************************************************/
MTCBB_API u32 mtGetLastError();

//��ȡwindows�ġ��˿ڼ���
MTCBB_API void mtGetWindowsTcpPortBitset(std::bitset<MAX_PORT_VALUE> &bstTcpState);

MTCBB_API BOOL32 mtGetLinuxTcpPortBitset(std::bitset<MAX_PORT_VALUE> &bstTcpState);


//��ȡwindows�ġ��˿ڼ���
MTCBB_API void mtGetWindowsUdpPortBitset(std::bitset<MAX_PORT_VALUE> &bstUdpState);

MTCBB_API BOOL32 mtGetLinuxUdpPortBitset(std::bitset<MAX_PORT_VALUE> &bstUdpState);




}


#endif // _MTUTILSSYSTEM_H_