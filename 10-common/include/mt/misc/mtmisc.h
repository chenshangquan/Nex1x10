/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   小业务子系统公用头文件
 * @author  瞿戴沣
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/


#ifndef _MT_MISC_H_
#define _MT_MISC_H_


#include "kdvtype.h"
#include "mtstruct.h"
#include "mtmacro.h"

/**---------------------------------------------------------------------- 
* 
* @brief    启动小业务子系统
* 
* @param	无
* @return   TRUE:  成功
*           FALSE：失败
------------------------------------------------------------------------*/
extern "C" MTCBB_API BOOL32 MiscStart(TMdlStartParam &tMdlStartparam);



/**---------------------------------------------------------------------- 
* 
* @brief    停止小业务子系统
* 
* @param	无
* @return   TRUE:  成功
*           FALSE：失败
------------------------------------------------------------------------*/
extern "C" MTCBB_API BOOL32 MiscStop();


#endif //_MT_MISC_H_