/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   mtLog模块调试命令
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
 * 
 */
/*---------------------------------------------------------------------------*/

#ifndef _MTLOG_HELP_H_
#define _MTLOG_HELP_H_


#include "osp.h"



/** ***********************************************************
* 
* @brief    时间戳开关
* @note     默认只显示时/分/秒/毫秒 
*
* @param	[in] bOn  是否开启
* @return	无
*
**************************************************************/
API void mtlogts(BOOL32 bOn);


/** ***********************************************************
* 
* @brief    详细时间信息打印开关
* @note     默认不显示年月日 此开关控制年月日的显示
*
* @param	[in] bOn  是否开启
* @return	无
*
**************************************************************/
API void mtlogtsdetail(BOOL32 bOn);



/** ***********************************************************
* 
* @brief    线程id打印开关
*
* @param	[in] bOn  是否开启
* @return	无
*
**************************************************************/
API void mtlogtid(BOOL32 bOn);



/** ***********************************************************
* 
* @brief    通过模块ID开启指定模块 Err | Warn | Hint 等级日志打印
*
* @param	[in] emModule        日志模块ID
* @return	无
* @note     emModule为0开启所有模块
*
**************************************************************/
API void mtlogon(EmMtLogModule emModule);



/** ***********************************************************
* 
* @brief    通过模块名开启指定模块 Err | Warn | Hint 等级日志打印
*
* @param	[in] pchMouduleName        日志模块名
* @return	无
* @note     模块名为空开启所有模块
*
**************************************************************/
API void mtlogonn(const s8 *pchMouduleName);


/** ***********************************************************
* 
* @brief    通过模块ID开启指定模块 debug | trace 等级日志打印
*
* @param	[in] emModule 日志模块ID
* @return	无
* @note     模块名为空开启所有模块
*
**************************************************************/
API void mtlogdbgon(EmMtLogModule emModule);



/** ***********************************************************
* 
* @brief    通过模块名开启指定模块 debug | trace 等级日志打印
*
* @param	[in] pchMouduleName 日志模块名
* @return	无
* @note     模块名为空开启所有模块
*
**************************************************************/
API void mtlogdbgonn(const s8 *pchMouduleName);



/** ***********************************************************
* 
* @brief    通过模块ID关闭指定模块 Err | Warn | Hint 等级日志打印
*
* @param	[in] emModule        日志模块ID
* @return	无
* @note     emModule为0关闭所有模块
*
**************************************************************/
API void mtlogoff(EmMtLogModule emModule);



/** ***********************************************************
* 
* @brief    通过模块名关闭指定模块 Err | Warn | Hint 等级日志打印
*
* @param	[in] pchMouduleName        日志模块名
* @return	无
* @note     模块名为空关闭所有模块
*
**************************************************************/
API void mtlogoffn(const s8 *pchMouduleName);



/** ***********************************************************
* 
* @brief    通过模块ID关闭指定模块 debug | trace 等级日志打印
*
* @param	[in] emModule 日志模块ID
* @return	无
* @note     模块名为空关闭所有模块
*
**************************************************************/
API void mtlogdbgoff(EmMtLogModule emModule);



/** ***********************************************************
* 
* @brief    通过模块名关闭指定模块 debug | trace 等级日志打印
*
* @param	[in] pchMouduleName 日志模块名
* @return	无
* @note     模块名为空关闭所有模块
*
**************************************************************/
API void mtlogdbgoffn(s8 * pchModuleName);



/** ***********************************************************
* 
* @brief    通过模块ID开启特定模块特定等级打印
*
* @param	[in] pchMouduleName 日志模块名
* @return	无
* @note     模块ID为空开启所有模块
*
**************************************************************/
API void mtloglvon(EmMtLogType emType, EmMtLogModule emModule);



/** ***********************************************************
* 
* @brief    通过模块ID关闭特定模块特定等级打印
*
* @param	[in] pchMouduleName 日志模块名
* @return	无
* @note     模块ID为空关闭所有模块
*
**************************************************************/
API void mtloglvoff(EmMtLogType emType, EmMtLogModule emModule);



/** ***********************************************************
* 
* @brief    日志帮助信息
*
* @param	无
* @return	无
* @note     无
*
**************************************************************/
API void mtloghelp();



/** ***********************************************************
* 
* @brief    日志模块状态信息
*
* @param	无
* @return	无
* @note     无
*
**************************************************************/
API void mtlogshow();



#endif  //_MTLOG_HELP_H_