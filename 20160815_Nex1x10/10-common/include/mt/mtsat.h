/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   卫星模块公共头文件
 * @author  瞿戴沣
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/

#ifndef MT_SAT_H_ 
#define MT_SAT_H_

#include "kdvtype.h"
#include "mtstruct.h"
#include "mtmacro.h"


/**---------------------------------------------------------------------- 
* 
* @brief    启动卫星模块
* 
* @param	无
* @return   TRUE:  成功
*           FALSE：失败
------------------------------------------------------------------------*/
extern "C" MTCBB_API BOOL32 MtSatStart(TMdlStartParam &tMdlStartParam);


/**---------------------------------------------------------------------- 
* 
* @brief    停止卫星模块
* 
* @param	无
* @return   TRUE:  成功
*           FALSE：失败
------------------------------------------------------------------------*/
extern "C" MTCBB_API BOOL32 MtSatStop();


/**---------------------------------------------------------------------- 
* 
* @brief    提供给系统控制调用
* 
* @param	无
* @return   无
------------------------------------------------------------------------*/
extern "C" MTCBB_API void MtSatAddStaticLib();


#endif //MT_SAT_H_