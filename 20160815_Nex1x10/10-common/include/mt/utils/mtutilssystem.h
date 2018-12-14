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
#ifndef _MTUTILSSYSTEM_H_
#define _MTUTILSSYSTEM_H_
#include "mtutilstype.h"
#include "kdvtype.h"
#include "mtmacro.h"
#include "mtconst.h"
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
* @namespace    MTUTILS
******************************************************************************/
namespace MTUTILS {

/*!**********************************************************
* @fn      EmOSType mtGetOsType()
* @brief   获取操作系统类型
* @return  操作系统类型
*************************************************************/
MTCBB_API EmMtOSType mtGetOsType();

/*!**********************************************************
* @fn      u32 mtGetCurrentThreadID ()
* @brief   获取当前线程标识符
* @return  线程ID
*************************************************************/
MTCBB_API u32 mtGetCurrentThreadID();

/*!**********************************************************
* @fn      u32 mtGetPID ()
* @brief   获取当前进程标识符
* @return  进程ID
*************************************************************/
MTCBB_API u32 mtGetPID();

/*!**********************************************************
* @fn      BOOL32 mtIsLittleEndian()
* @brief   获取CPU字节序
* @return  TRUE:小端模式  FALSE:大端模式
*************************************************************/
MTCBB_API BOOL32 mtIsLittleEndian();

/*!**********************************************************
* @fn      u32 mtGetSysRunTime()
* @brief   Linux获取系统已运行时间
* @return  系统的已运行时间（单位:秒）
*************************************************************/
MTCBB_API u32 mtGetSysRunTime();

/*!**********************************************************
* @fn      u32 mtGetSysIdleTime()
* @brief   Linux获取系统空闲时间
* @return  系统空闲时间（单位:秒）
*************************************************************/
MTCBB_API u32 mtGetSysIdleTime();

/*!**********************************************************
* @fn      u32 mtGetTickCount()
* @brief   从操作系统启动到现在所经过的毫秒数
* @return  时间（单位:毫秒）
*************************************************************/
MTCBB_API u32 mtGetTickCount();

/*!**********************************************************
* @fn      u32 mtGetCurTime()
* @brief   获取当前系统时间,精确到毫秒
* @param   [out] tTime  当前系统时间
* @return  无
*************************************************************/
MTCBB_API void mtGetCurTime(TDateTime &tDateTime);

/*!**********************************************************
* @fn      u32 mtGetCurWorkDir(s8 *pchPath, u32 dwLen)
* @brief   获取程序当前工作路径
* @param   [out] pchPath  当前工作路径
* @param   [in]  dwLen    缓冲区长度
* @return  MT_SUCCESS:成功 
           ERR_MTCBB_BUF_OVERFLOW: buf太小
*************************************************************/
MTCBB_API u32 mtGetCurrentWorkDir(s8 *pchPath, u32 dwLen);

/*!**********************************************************
* @fn      u32 mtCreateFile(const s8 *pchPath)
* @brief   新建文件
* @param   [in] pchPath  文件路径, utf8编码
* @return  MT_SUCCESS:成功 
		   ERR_MTCBB_PATH_EXIST:   失败 文件已存在
		   ERR_MTCBB_INVALID_PATH: 失败 非法路径
*************************************************************/
MTCBB_API u32 mtCreateFile(const s8 *pchPath);

/*!**********************************************************
* @fn      u32 mtMakeDir(const s8 *pchPath)
* @brief   新建文件夹
* @param   [in] pchPath  文件夹路径, utf8编码
* @return  MT_SUCCESS:成功 
		   ERR_MTCBB_INVALID_PATH: 失败
*************************************************************/
MTCBB_API u32 mtMakeDir(const s8 *pchPath);

/*!**********************************************************
* @fn      u32 mtMakeDir(const s8 *pchPath)
* @brief   创建层级文件夹  如 /usr/dir1/dir2/dir3
* @param   [in] pchPath  文件夹路径, utf8编码
* @return  MT_SUCCESS: 成功 
           ERR_MTCBB_INVALID_PATH: 失败
*************************************************************/
MTCBB_API u32 mtMakeHierarchyDir(const s8 *pchPath);

/*!**********************************************************
* @fn      u32 mtIsPathExist(const s8 *pchPath)
* @brief   判断路径是否存在
* @param   [in] pchPath, utf8编码
* @return  TRUE: 存在 
           FALSE: 不存在
*************************************************************/
MTCBB_API BOOL32 mtIsPathExist(const s8 *pchPath);

/*!**********************************************************
* @fn      u32 mtIsFileExist(const s8 *pchFilename)
* @brief   判断文件是否存在
* @param   [in] pchFilename 文件名, utf8编码
* @return  TRUE: 存在 
           FALSE: 不存在
*************************************************************/
MTCBB_API BOOL32 mtIsFileExist(const s8 *pchFilename);

/*!**********************************************************
* @fn      u32 mtRenameFile(const s8 *pchOldPath, const s8 *pchNewPath)
* @brief   重命名文件(路径)
* @param   [in] pchOldPath 当前名称, utf8编码
* @param   [in] pchNewPath 修改后的名称, utf8编码
* @return  MT_SUCCESS: 成功 
           MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtRenameFile(const s8 *pchOldPath, const s8 *pchNewPath);

/*!**********************************************************
* @fn      u32 mtAttribFile(const s8 *pchFileName, BOOL32 bReadOnly)
* @brief   修改文件读写属性
* @param   [in] pchFileName 文件名, utf8编码
* @param   [in] bReadOnly   只读 / 可读写
* @return  MT_SUCCESS:成功 
           MT_FAILED:失败
*************************************************************/
MTCBB_API u32 mtAttribFile(const s8 *pchFileName, BOOL32 bReadOnly);

/*!**********************************************************
* 
* @brief   获取文件大小
* @param   [in] pchFileName 文件名, utf8编码
* @param   [out] dwSize     文件大小
*
* @return  MT_SUCCESS:成功 
           MT_FAILED:失败
*************************************************************/
MTCBB_API u32 mtGetFileSize(const s8 *pchFileName, u32 &dwSize);


/*!**********************************************************
*
* @brief   创建进程
* @param   [in]  pchAppPath      进程路径名, utf8编码
* @param   [in]  pchCmdLine      命令行参数
* @param   [out] dwProcessId     创建的进程的进程ID
* @param   [out] pProcessHandle  (WIN32)创建的进程的句柄
*
* @return  MT_SUCCESS:成功 
           MT_FAILED:失败
*************************************************************/
MTCBB_API u32 mtCreateProcess(const s8 *pchAppPath, const s8 *pchCmdLine, u32 &dwProcessId, void *pProcessHandle = NULL);

/*!**********************************************************
*
* @brief   业务中申请端口后若不会马上用到 可用此接口绑定端口
*          防止被占用用到时再解绑
* @param   [in]  wPort 端口
*
* @return  MT_SUCCESS:成功 
           MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtBindUdpPort(u16 wPort);

/*!**********************************************************
*
* @brief   解绑由mtBindUdpPort绑定的端口
*          
* @param   [in]  wPort 端口
*
* @return  MT_SUCCESS:成功 
           MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtUnBindUdpPort(u16 wPort);

/*!**********************************************************
*
* @brief   删除文件
*          
* @param   [in]  pchFilePath 文件路径, utf8编码
*
* @return  MT_SUCCESS:成功 
           MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtRemoveFile(const s8 *pchFilePath);

/*!**********************************************************
*
* @brief   判断tcp端口是否被使用
*          
* @param   [in]  wTcpPort 端口号
*
* @return  TRUE:被使用 
           FALSE: 未使用
*************************************************************/
MTCBB_API BOOL32 mtIsTcpPortUsed(u16 wTcpPort);

/*!**********************************************************
*
* @brief   判断udp端口是否被使用
*          
* @param   [in]  wUdpPort 端口号
*
* @return  TRUE:被使用 
           FALSE: 未使用
*************************************************************/
MTCBB_API BOOL32 mtIsUdpPortUsed(u16 wUdpPort);

/*!**********************************************************
*
* @brief   获取最后一次错误码
*          
* @param   
*
* @return   错误码
*************************************************************/
MTCBB_API u32 mtGetLastError();

//获取windows的　端口集合
MTCBB_API void mtGetWindowsTcpPortBitset(std::bitset<MAX_PORT_VALUE> &bstTcpState);

MTCBB_API BOOL32 mtGetLinuxTcpPortBitset(std::bitset<MAX_PORT_VALUE> &bstTcpState);


//获取windows的　端口集合
MTCBB_API void mtGetWindowsUdpPortBitset(std::bitset<MAX_PORT_VALUE> &bstUdpState);

MTCBB_API BOOL32 mtGetLinuxUdpPortBitset(std::bitset<MAX_PORT_VALUE> &bstUdpState);




}


#endif // _MTUTILSSYSTEM_H_