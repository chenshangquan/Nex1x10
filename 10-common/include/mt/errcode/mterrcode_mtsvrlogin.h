/**===========================================================================
 * @file    $Id$
 * @brief   负责MTDATASHARE业务模块的错误码定义
 * @author  钱霖
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MTERRORCODE_MTSVRLOGIN_H_
#define _MTERRORCODE_MTSVRLOGIN_H_
#include "kdvtype.h"
#include "mterrcode_api.h"
#include "mterrcode_def.h"
/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief 错误码规则(10进制表示)
 *	 99                   99                    9             9999
 *	模块        +      子业务分类      +     错误等级    +   分配数量
 *(2位/100个)        （2位/100个）          （1位/10个）     (4位/10000个)
 */

/** MTSVRLOGIN业务模块的子业务模块ID定义, 新增子业务分类定义只能往后追加 */
enum EM_ERR_SUBMOD_MTSVRLOGIN
{
    emErrSubModCtrl = 0,         ///< 服务器登录控制
	emErrSubModDns,              ///< 服务器登录域名解析
	emErrSubModXap,              ///< 服务器登录xap
};
//////////////////////////////////////////////////////////// Base //////////////////////////////////////////////////////////////////////////////////////
/** 服务器登录控制基本错误码定义 */
enum EmSvrLoginCtrlErrorId
{
	ERR_SvrLoginCtrl_None = 0,
	ERR_OverwriteValidIp,
	ERR_IpValid,
	ERR_TranslateDomain,
	ERR_NoSvrAddr,
	ERR_SvrTypeInvalid,
	ERR_DomainTranslateFail,
	ERR_CBCheckAddrMissing,
	ERR_SvrLoginCtrl_End,
};
/** 服务器登录域名解析基本错误码定义 */
enum EmSvrLoginDnsErrorId
{

};
/** 服务器登录xap登录基本错误码定义 */
enum EmSvrLoginXapErrorId
{
	ERR_SvrLoginXap_None = 0,
	ERR_StateUnmatch,
	ERR_NewIpExist,
	ERR_SvrLoginXap_End
};



/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _MTERRORCODE_MTSVRLOGIN_H_