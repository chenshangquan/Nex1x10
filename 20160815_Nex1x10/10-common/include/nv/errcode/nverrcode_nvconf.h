/**===========================================================================
 * @file    $Id$
 * @brief   负责NVCONF业务模块的错误码定义
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _NVERRORCODE_NVCONF_H_
#define _NVERRORCODE_NVCONF_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief 错误码规则(10进制表示)
 *	 99                   99                    9             9999
 *	模块        +      子业务分类      +     错误等级    +   分配数量
 *(2位/100个)        （2位/100个）          （1位/10个）     (4位/10000个)
 */

/** NVCONF业务模块的子业务模块ID定义, 新增子业务分类定义只能往后追加 */
enum EM_ERR_SUBMOD_NVCONF
{
    emErrSubModNvConf_Call = 0,              ///< conf模块 呼叫部分
	emErrSubModNvConf_Chan = 1,              ///< conf模块 通道处理部分
	emErrSubModNvConf_ConfCtrl = 2,          ///< conf模块 会控部分
	emErrSubModNvConf_Reg = 3,               ///< conf模块 注册部分
	emErrSubModNvConf_Nvpa = 4,              ///< nvpa模块错误
	
};

//////////////////////////////////////////////////////////// Call //////////////////////////////////////////////////////////////////////////////////////
/** nvconf业务模块呼叫部分错误码定义 */
#define  ERR_NVCONF_Call_WrongState                         (u32)1                           ///< 呼叫状态机不对
#define  ERR_NVCONF_Call_JoinConfWithNoE164                 (u32)2                           ///< 参加会议，会议e164号为空， 或者没带
#define  ERR_NVCONF_Call_CreateConfWithNoE164               (u32)3                           ///< 还没收到mcu的 conf e164的回应, 然后收到callincoming
#define  ERR_NVCONF_Call_MakeCallSateNoP2P                  (u32)4                           ///< 卫星终端么有p2p权限，呼叫   
/////////////////////////////////////////////////  END DEFINE/////////////////////////////////////////////////

//////////////////////////////////////////////////////////// Chan //////////////////////////////////////////////////////////////////////////////////////
/** nvconf业务模块呼叫部分错误码定义 */
#define  ERR_NVCONF_Chan_WrongState                         (u32)1                           ///< chan状态不对， 无法继续通道操作
#define  ERR_NVCONF_Chan_GetNullChan                        (u32)2                           ///< 获得空的chan对象， 无法继续通道操作
#define  ERR_NVCONF_Chan_GetWrongChan                       (u32)3                           ///< 获得错误的chan对象， 无法继续通道操作
/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////


//////////////////////////////////////////////////////////// Nvpa ////////////////////////////////////////////
/*nvpa模块呼叫错误码*/
#define  ERR_NVCONF_NVPA_InVaildCall                         (u32)1                          ///<呼叫句柄不对，呼叫无法继续 
 
/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////
#endif // _NVERRORCODE_NVCONF_H_