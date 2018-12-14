/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   系统升级模块头文件
 * @author  瞿戴沣
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/



#ifndef _NVUPGRADE_H_
#define _NVUPGRADE_H_

#include "nvmsg.h"
#include "nvstruct.pb.h"
#include "nvstruct.h"

namespace NVUPGRADE {

///< 升级组件对上层的回调函数, cMsg为已封装好的消息，sdk将其抛给上层
typedef void (*pfCbSysUpgrageCallback)(nvmsg::CNvMsg &cMsg);

/** ************************************************************
* 
* @brief    检测更新接口
*
* @param	[in] tInfo    检测更新所需终端信息
* @param	[in] pfFunc   上层提供的回调接口 处理升级组件构造的消息
* @param	[in] bGetRecommend    是否获取推荐版本 (TRUE:获取推荐版本  FALSE:获取版本列表)
* @return	无
* @note     
*
************************************************************* */
void nvCheckUpdate(nv::TNVUpgradeClientInfo &tInfo, pfCbSysUpgrageCallback pfFunc, BOOL32 bGetRecommend = TRUE);



/** ************************************************************
* 
* @brief    取消检测更新
*
* @param	无
* @return	无
* @note     
*
************************************************************* */
void nvCancelCheckUpdate();


/** ************************************************************
* 
* @brief    开始下载更新文件到指定目录
*
* @param	[in] pchFilePath 文件下载存放路径
* @param	[in] dwVerId     当请求得到的版本列表有多个时,指定要下载的版本
* @return	无
* @note     
*
************************************************************* */
void nvStartDownloadUpgradeFile(const s8 *pchFilePath, u32 dwVerId = 0);


/** ************************************************************
* 
* @brief    取消下载更新文件
*
* @param	无
* @return	无
* @note     
*
************************************************************* */
void nvCancelDownloadUpgradeFile();


/** ************************************************************
* 
* @brief    会议状态通知
*
* @param	无
* @return	无
* @note     升级文件的下载操作被会议或点播打断  会议结束或点播后重新提示
*
************************************************************* */
void SetDownloadState(BOOL32 bPause);


/** ************************************************************
* 
* @brief    开始升级(硬终端)
*
* @param	无
* @return	无
* @note     
*
************************************************************* */
void nvStartUpgrade();


};



/**---------------------------------------------------------------------- 
* 
* @brief    启动升级子系统
* 
* @param	无
* @return   TRUE:  成功
*           FALSE：失败
------------------------------------------------------------------------*/
extern "C" NVCBB_API BOOL32 UpgradeStart(TMdlStartParam &tMdlStartparam);



/**---------------------------------------------------------------------- 
* 
* @brief    停止升级子系统
* 
* @param	无
* @return   TRUE:  成功
*           FALSE：失败
------------------------------------------------------------------------*/
extern "C" NVCBB_API BOOL32 UpgradeStop();


#endif  //_NVUPGRADE_H_