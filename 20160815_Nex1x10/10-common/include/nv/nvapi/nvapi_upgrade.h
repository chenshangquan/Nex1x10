/*******************************************************************************//**
*@file          nvapi_upgrade.h
*@brief         提供升级服务器控制接口
*
*@author        yanglei
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _NVAPI_UPGRADE_H_
#define _NVAPI_UPGRADE_H_
/**@addtogroup api API接口
*@{
*/

/**@addtogroup upgradeapi 
*@{
*/

#include <string.h>
#include "nvapi_export.h"
#include "nvapi_typedef.h"
#include "nvapi_struct.h"
#include "nvstruct.pb.h"




/**
* KdvNv_UpgradeIsInited
* @brief  升级模块是否已经初始化
*           
* @return	u32 返回启动结果
* @note 
*/
KdvNvAPI BOOL32 KdvNvCALL KdvNv_UpgradeIsInited(  );


/**
* KdvNv_UpgradeUnInitalize
* @brief  升级模块释放退出
*
*           
* @return	u32 返回启动结果
* @note 
*/
KdvNvAPI BOOL32 KdvNvCALL KdvNv_UpgradeUnInitalize(  );

/**
* KdvNv_UpgradeInitalize
* @brief  初始化升级模块
*
*           
* @return	u32 返回启动结果
* @note 
*/
KdvNvAPI BOOL32 KdvNvCALL KdvNv_UpgradeInitalize(  );


/*******************************************************************************//**
*@brief         注册Observer(UI)通知回调(回调函数中响应消息处要与回调函数同步)
*             
*(注意：回调上去的参数不允许改变其值) 
*
*@author        
*@date     
*@param[in]     cbCallback  要注册的回调函数
*@return        void
*@note          
 ***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_UpgradeSetCallback( IN NOTIFY_NV_UPGRADE_CALLBACK cbCallback );

/**
* KdvNv_NvConnectUpgradeService
* @brief  连接升级服务器
*
* @param	[in] nv::TNVUpGradeConnectInfo 连接信息
*           
* @return	u32 返回启动结果
* @note 
*/
KdvNvAPI u32 KdvNvCALL KdvNv_NvConnectUpgradeService( IN CONST nv::TNVUpGradeConnectInfo &tConnectInfo );

/**
* KdvNv_NvLoginUpgradeService
* @brief  登入升级服务器
*
* @param	[in] nv::TNVLocalDevInfo 终端信息
*           
* @return	u32 返回启动结果
* @note 
*/
KdvNvAPI u32 KdvNvCALL KdvNv_NvLoginUpgradeService( IN CONST nv::TNVLocalDevInfo &tDevInfo );


/**
* KdvNv_NvDevUpgradReq
* @brief  升级请求
*
* @param	[in] nv::TNVLocalDevInfo 版本信息
*           
* @return	u32 返回启动结果
* @note 
*/
KdvNvAPI u32 KdvNvCALL KdvNv_NvDevUpgradReq( IN CONST nv::TNVLocalDevInfo &tDevInfo  );

/**@}*/
#endif 