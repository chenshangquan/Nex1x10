/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   系统相关公用函数接口
 * @author  瞿戴沣
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

 /////// bitset 里定义了std:min, std:max, 和外面自定义的min, max 冲突
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
* @brief   获取操作系统类型
* @return  操作系统类型
*************************************************************/
NVCBB_API EmNvOSType nvGetOsType();

/*!**********************************************************
* @fn      u32 nvGetCurrentThreadID ()
* @brief   获取当前线程标识符
* @return  线程ID
*************************************************************/
NVCBB_API u32 nvGetCurrentThreadID();

/*!**********************************************************
* @fn      u32 nvGetPID ()
* @brief   获取当前进程标识符
* @return  进程ID
*************************************************************/
NVCBB_API u32 nvGetPID();

/*!**********************************************************
* @fn      BOOL32 nvIsLittleEndian()
* @brief   获取CPU字节序
* @return  TRUE:小端模式  FALSE:大端模式
*************************************************************/
NVCBB_API BOOL32 nvIsLittleEndian();

/*!**********************************************************
* @fn      u32 nvGetSysRunTime()
* @brief   Linux获取系统已运行时间
* @return  系统的已运行时间（单位:秒）
*************************************************************/
NVCBB_API u32 nvGetSysRunTime();

/*!**********************************************************
* @fn      u32 nvGetSysIdleTime()
* @brief   Linux获取系统空闲时间
* @return  系统空闲时间（单位:秒）
*************************************************************/
NVCBB_API u32 nvGetSysIdleTime();

/*!**********************************************************
* @fn      u32 nvGetTickCount()
* @brief   从操作系统启动到现在所经过的毫秒数
* @return  时间（单位:毫秒）
*************************************************************/
NVCBB_API u32 nvGetTickCount();

/*!**********************************************************
* @fn      u32 nvGetCurTime()
* @brief   获取当前系统时间,精确到毫秒
* @param   [out] tTime  当前系统时间
* @return  无
*************************************************************/
NVCBB_API void nvGetCurTime(TDateTime &tDateTime);

/*!**********************************************************
* @fn      u32 nvGetCurWorkDir(s8 *pchPath, u32 dwLen)
* @brief   获取程序当前工作路径
* @param   [out] pchPath  当前工作路径
* @param   [in]  dwLen    缓冲区长度
* @return  NV_SUCCESS:成功 
           ERR_NVCBB_BUF_OVERFLOW: buf太小
*************************************************************/
NVCBB_API u32 nvGetCurrentWorkDir(s8 *pchPath, u32 dwLen);

/*!**********************************************************
* @fn      u32 nvCreateFile(const s8 *pchPath)
* @brief   新建文件
* @param   [in] pchPath  文件路径, utf8编码
* @return  NV_SUCCESS:成功 
		   ERR_NVCBB_PATH_EXIST:   失败 文件已存在
		   ERR_NVCBB_INVALID_PATH: 失败 非法路径
*************************************************************/
NVCBB_API u32 nvCreateFile(const s8 *pchPath);

/*!**********************************************************
* @fn      u32 nvMakeDir(const s8 *pchPath)
* @brief   新建文件夹
* @param   [in] pchPath  文件夹路径, utf8编码
* @return  NV_SUCCESS:成功 
		   ERR_NVCBB_INVALID_PATH: 失败
*************************************************************/
NVCBB_API u32 nvMakeDir(const s8 *pchPath);

/*!**********************************************************
* @fn      u32 nvMakeDir(const s8 *pchPath)
* @brief   创建层级文件夹  如 /usr/dir1/dir2/dir3
* @param   [in] pchPath  文件夹路径, utf8编码
* @return  NV_SUCCESS: 成功 
           ERR_NVCBB_INVALID_PATH: 失败
*************************************************************/
NVCBB_API u32 nvMakeHierarchyDir(const s8 *pchPath);

/*!**********************************************************
* @fn      u32 nvIsPathExist(const s8 *pchPath)
* @brief   判断路径是否存在
* @param   [in] pchPath, utf8编码
* @return  TRUE: 存在 
           FALSE: 不存在
*************************************************************/
NVCBB_API BOOL32 nvIsPathExist(const s8 *pchPath);

/*!**********************************************************
* @fn      u32 nvIsFileExist(const s8 *pchFilename)
* @brief   判断文件是否存在
* @param   [in] pchFilename 文件名, utf8编码
* @return  TRUE: 存在 
           FALSE: 不存在
*************************************************************/
NVCBB_API BOOL32 nvIsFileExist(const s8 *pchFilename);

/*!**********************************************************
* @fn      u32 nvRenameFile(const s8 *pchOldPath, const s8 *pchNewPath)
* @brief   重命名文件(路径)
* @param   [in] pchOldPath 当前名称, utf8编码
* @param   [in] pchNewPath 修改后的名称, utf8编码
* @return  NV_SUCCESS: 成功 
           NV_FAILED: 失败
*************************************************************/
NVCBB_API u32 nvRenameFile(const s8 *pchOldPath, const s8 *pchNewPath);

/*!**********************************************************
* @fn      u32 nvAttribFile(const s8 *pchFileName, BOOL32 bReadOnly)
* @brief   修改文件读写属性
* @param   [in] pchFileName 文件名, utf8编码
* @param   [in] bReadOnly   只读 / 可读写
* @return  NV_SUCCESS:成功 
           NV_FAILED:失败
*************************************************************/
NVCBB_API u32 nvAttribFile(const s8 *pchFileName, BOOL32 bReadOnly);

/*!**********************************************************
* 
* @brief   获取文件大小
* @param   [in] pchFileName 文件名, utf8编码
* @param   [out] dwSize     文件大小
*
* @return  NV_SUCCESS:成功 
           NV_FAILED:失败
*************************************************************/
NVCBB_API u32 nvGetFileSize(const s8 *pchFileName, u32 &dwSize);


/*!**********************************************************
*
* @brief   创建进程
* @param   [in]  pchAppPath      进程路径名, utf8编码
* @param   [in]  pchCmdLine      命令行参数
* @param   [out] dwProcessId     创建的进程的进程ID
* @param   [out] pProcessHandle  (WIN32)创建的进程的句柄
*
* @return  NV_SUCCESS:成功 
           NV_FAILED:失败
*************************************************************/
NVCBB_API u32 nvCreateProcess(const s8 *pchAppPath, const s8 *pchCmdLine, u32 &dwProcessId, void *pProcessHandle = NULL);

/*!**********************************************************
*
* @brief   业务中申请端口后若不会马上用到 可用此接口绑定端口
*          防止被占用用到时再解绑
* @param   [in]  wPort 端口
*
* @return  NV_SUCCESS:成功 
           NV_FAILED: 失败
*************************************************************/
NVCBB_API u32 nvBindUdpPort(u16 wPort);

/*!**********************************************************
*
* @brief   解绑由nvBindUdpPort绑定的端口
*          
* @param   [in]  wPort 端口
*
* @return  NV_SUCCESS:成功 
           NV_FAILED: 失败
*************************************************************/
NVCBB_API u32 nvUnBindUdpPort(u16 wPort);

/*!**********************************************************
*
* @brief   删除文件
*          
* @param   [in]  pchFilePath 文件路径, utf8编码
*
* @return  NV_SUCCESS:成功 
           NV_FAILED: 失败
*************************************************************/
NVCBB_API u32 nvRemoveFile(const s8 *pchFilePath);

/*!**********************************************************
*
* @brief   判断tcp端口是否被使用
*          
* @param   [in]  wTcpPort 端口号
*
* @return  TRUE:被使用 
           FALSE: 未使用
*************************************************************/
NVCBB_API BOOL32 nvIsTcpPortUsed(u16 wTcpPort);

/*!**********************************************************
*
* @brief   判断udp端口是否被使用
*          
* @param   [in]  wUdpPort 端口号
*
* @return  TRUE:被使用 
           FALSE: 未使用
*************************************************************/
NVCBB_API BOOL32 nvIsUdpPortUsed(u16 wUdpPort);

/*!**********************************************************
*
* @brief   获取最后一次错误码
*          
* @param   
*
* @return   错误码
*************************************************************/
NVCBB_API u32 nvGetLastError();

//获取windows的　端口集合
NVCBB_API void nvGetWindowsTcpPortBitset(std::bitset<MAX_PORT_VALUE> &bstTcpState);

NVCBB_API BOOL32 nvGetLinuxTcpPortBitset(std::bitset<MAX_PORT_VALUE> &bstTcpState);


//获取windows的　端口集合
NVCBB_API void nvGetWindowsUdpPortBitset(std::bitset<MAX_PORT_VALUE> &bstUdpState);

NVCBB_API BOOL32 nvGetLinuxUdpPortBitset(std::bitset<MAX_PORT_VALUE> &bstUdpState);




}


#endif // _NVUTILSSYSTEM_H_