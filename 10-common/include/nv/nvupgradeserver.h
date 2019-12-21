#ifndef _NVUPGRADESERVER_H_
#define _NVUPGRADESERVER_H_

#include "nvstruct.h"
#include "nvmacro.h"


/** ************************************************************
* 
* @brief    启动升级服务器入口函数
*
* @param	
* @return	无
* @note     启动升级服务器入口函数
*
************************************************************* */
void StartNvUpGradeServer( );

/** ************************************************************
* 
* @brief    结束升级服务器入口函数
*
* @param	无
* @return	无
* @note     结束升级服务器入口函数
*
************************************************************* */
void StopNvUpGradeServer();

#endif	// _NVSYSCTRL_H_